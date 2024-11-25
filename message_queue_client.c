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

    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    // 사용자로부터 메시지 입력 받기
    while (1) {
        printf("보낼 메시지를 입력하세요 (종료하려면 'exit' 입력): ");
        fgets(message.mtext, MAX_MSG_SIZE, stdin);
        message.mtype = 1;

        // 메시지 보내기
        if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
            perror("msgsnd failed");
            exit(1);
        }

        // 종료 조건
        if (strcmp(message.mtext, "exit\n") == 0) {
            break;
        }
    }

    return 0;
}
