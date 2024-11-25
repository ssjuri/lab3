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

    // 메시지 큐 열기
    msgid = msgget(MSG_KEY, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("채팅 수신 대기 중...\n");

    while (1) {
        ssize_t bytes_read = msgrcv(msgid, &message, MAX_MSG_SIZE, 0, 0);
        if (bytes_read == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("받은 메시지: %s", message.msg_text);
    }

    return 0;
}
