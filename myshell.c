#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100

// SIGINT와 SIGQUIT 처리 함수
void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("\nReceived SIGINT (Ctrl-C)\n");
    } else if (sig == SIGQUIT) {
        printf("\nReceived SIGQUIT (Ctrl-Z)\n");
    }
}

// 명령어를 파싱하는 함수
void parse_command(char *cmd, char **args, int *bg) {
    char *token = strtok(cmd, " \t\n");
    int i = 0;
    *bg = 0;
    while (token != NULL) {
        if (strcmp(token, "&") == 0) {
            *bg = 1;  // 백그라운드 실행 플래그 설정
            break;
        }
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

// 명령어 실행 함수
void execute_command(char **args, int bg) {
    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // 부모 프로세스
        if (!bg) {
            // 백그라운드가 아니라면 자식 프로세스가 종료될 때까지 기다림
            waitpid(pid, NULL, 0);
        }
    }
}

// 파일 재지향 및 파이프 처리 함수
void redirect_io(char **args, int *in_fd, int *out_fd, int *pipe_fd) {
    for (int i = 0; args[i] != NULL; i++) {
        // 입력 리디렉션 (>)
        if (strcmp(args[i], ">") == 0) {
            *out_fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            args[i] = NULL;
            break;
        }
        // 출력 리디렉션 (<)
        if (strcmp(args[i], "<") == 0) {
            *in_fd = open(args[i+1], O_RDONLY);
            args[i] = NULL;
            break;
        }
        // 파이프 (|)
        if (strcmp(args[i], "|") == 0) {
            pipe(pipe_fd);
            args[i] = NULL;
            break;
        }
    }
}

// 명령어 실행과 파일 재지향, 파이프 처리
void execute_with_redirection_and_pipe(char **args) {
    int in_fd = 0, out_fd = 1, pipe_fd[2];
    redirect_io(args, &in_fd, &out_fd, pipe_fd);

    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스
        if (in_fd != 0) {
            dup2(in_fd, 0);  // 입력 파일 디스크립터 재지향
            close(in_fd);
        }
        if (out_fd != 1) {
            dup2(out_fd, 1);  // 출력 파일 디스크립터 재지향
            close(out_fd);
        }
        if (pipe_fd[1] != 1) {
            dup2(pipe_fd[1], 1);  // 파이프 출력 재지향
            close(pipe_fd[1]);
        }
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        // 부모 프로세스
        if (pipe_fd[0] != 0) {
            close(pipe_fd[0]);  // 파이프 닫기
        }
        waitpid(pid, NULL, 0);  // 자식 프로세스 종료 대기
    }
}

// 기본 명령어 처리 함수
void handle_basic_commands(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL || chdir(args[1]) == -1) {
            perror("cd");
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[MAX_CMD_LEN];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("pwd");
        }
    } else if (strcmp(args[0], "ls") == 0) {
        execvp("ls", args);
    } else if (strcmp(args[0], "mkdir") == 0) {
        execvp("mkdir", args);
    } else {
        execute_with_redirection_and_pipe(args);
    }
}

int main() {
    signal(SIGINT, handle_signal);  // SIGINT 처리
    signal(SIGQUIT, handle_signal); // SIGQUIT 처리

    char cmd[MAX_CMD_LEN];
    char *args[MAX_ARGS];
    int bg;

    while (1) {
        printf("myshell> ");
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }

        parse_command(cmd, args, &bg);

        if (args[0] != NULL) {
            handle_basic_commands(args);
        }
    }

    return 0;
}
