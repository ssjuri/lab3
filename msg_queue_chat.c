#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_MSG_SIZE 100

// 메시지 구조체 정의
struct msgbuf {
    long mtype;               // 메시지 유형
    char mtext[MAX_MSG_SIZE]; // 메시지 내용
};

void chat(int msgid) {
    struct msgbuf message;
    pid_t pid = fork();

    if (pid > 0) {  // 부모 프로세스 (메시지 보내기)
        while (1) {
            printf("보낼 메시지 (종료하려면 'exit' 입력): ");
            fgets(message.mtext, MAX_MSG_SIZE, stdin);
            message.mtext[strcspn(message.mtext, "\n")] = '\0'; // 개행문자 제거

            // 'exit' 입력 시 채팅 종료
            if (strcmp(message.mtext, "exit") == 0) {
                break;
            }

            message.mtype = 1;  // 메시지 유형 설정
            if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
                perror("msgsnd");
                exit(1);
            }
        }
    } else if (pid == 0) {  // 자식 프로세스 (메시지 받기)
        while (1) {
            if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
                perror("msgrcv");
                exit(1);
            }

            // 'exit' 메시지를 받으면 종료
            if (strcmp(message.mtext, "exit") == 0) {
                break;
            }

            printf("상대방: %s\n", message.mtext);
        }
    } else {
        perror("fork");
        exit(1);
    }

    // 메시지 큐 삭제
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
}

int main() {
    key_t key;
    int msgid;

    // 고유한 키 생성
    key = ftok("/tmp", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // 메시지 큐 생성
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("채팅 프로그램 시작! (종료하려면 'exit' 입력)\n");
    chat(msgid);

    return 0;
}
