#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_MSG_SIZE 256
#define MSG_KEY 1234

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_MSG_SIZE];
};

int main() {
    int msgid;
    struct msg_buffer message;

    // 메시지 큐 생성
    msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("채팅 프로그램 시작 (종료하려면 'exit' 입력)\n");

    while (1) {
        printf("보낼 메시지를 입력하세요: ");
        fgets(message.msg_text, MAX_MSG_SIZE, stdin);

        // 입력이 'exit'이면 종료
        if (strncmp(message.msg_text, "exit", 4) == 0) {
            break;
        }

        // 메시지 전송
        message.msg_type = 1;
        if (msgsnd(msgid, &message, strlen(message.msg_text) + 1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
    }

    // 메시지 큐 삭제
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
