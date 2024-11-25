#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100

// 메시지 구조체 정의
struct msgbuf {
    long mtype;
    char mtext[MAX_MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf message;

    // 파일 경로 변경 (이미 존재하는 파일 사용)
    key = ftok("/tmp", 65);  // /tmp 디렉토리의 파일을 이용하여 고유 키 생성
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("서버 시작, 클라이언트로부터 메시지를 기다리는 중...\n");

    // 메시지 받기
    while (1) {
        if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
            perror("msgrcv failed");
            exit(1);
        }

        printf("클라이언트로부터 받은 메시지: %s\n", message.mtext);

        // 종료 조건: "exit" 메시지가 들어오면 종료
        if (strcmp(message.mtext, "exit") == 0) {
            printf("서버 종료\n");
            break;
        }
    }

    // 메시지 큐 삭제
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl failed");
        exit(1);
    }

    return 0;
}
