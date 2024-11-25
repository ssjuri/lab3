#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "안녕하세요, 자식 프로세스!";
    char read_msg[100];

    // 파이프 생성
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    // 자식 프로세스 생성
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {  // 부모 프로세스
        close(pipefd[0]);  // 읽기용 끝을 닫음

        // 파이프에 메시지 쓰기
        write(pipefd[1], write_msg, sizeof(write_msg));

        close(pipefd[1]);  // 메시지 전송 후 쓰기 끝 닫기
    } else {  // 자식 프로세스
        close(pipefd[1]);  // 쓰기용 끝을 닫음

        // 파이프에서 메시지 읽기
        read(pipefd[0], read_msg, sizeof(read_msg));

        printf("자식 프로세스에서 읽은 메시지: %s\n", read_msg);

        close(pipefd[0]);  // 읽기 끝 닫기
    }

    return 0;
}
