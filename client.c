#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSG_SIZE 100

struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // 메시지 큐 생성 (서버와 동일한 키)
    key = ftok("chat_program", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);  // 메시지 큐 생성

    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    while (1) {
        // 클라이언트에서 서버로 메시지 보내기
        printf("메시지를 입력하세요: ");
        fgets(message.msg_text, MSG_SIZE, stdin);
        message.msg_type = 1;  // 클라이언트 메시지 타입

        if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
            perror("msgsnd failed");
            exit(1);
        }

        if (strncmp(message.msg_text, "exit", 4) == 0) {
            break;
        }

        // 서버의 응답 받기 (타입 2)
        if (msgrcv(msgid, &message, sizeof(message), 2, 0) == -1) {
            perror("msgrcv failed");
            exit(1);
        }

        printf("서버 응답: %s", message.msg_text);
    }

    // 메시지 큐 삭제
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
