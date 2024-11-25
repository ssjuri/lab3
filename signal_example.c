#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// 시그널 처리 함수
void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("Ctrl+C (SIGINT) 시그널을 받았습니다. 프로그램을 종료합니다.\n");
        exit(0);  // 프로그램 종료
    } else if (sig == SIGTERM) {
        printf("SIGTERM 시그널을 받았습니다. 프로그램을 종료합니다.\n");
        exit(0);  // 프로그램 종료
    } else if (sig == SIGSEGV) {
        printf("SIGSEGV (Segmentation Fault) 시그널을 받았습니다. 종료합니다.\n");
        exit(1);  // 프로그램 비정상 종료
    }
}

int main() {
    // 시그널 처리기 등록
    signal(SIGINT, handle_signal);   // Ctrl+C
    signal(SIGTERM, handle_signal);  // kill 명령으로 종료
    signal(SIGSEGV, handle_signal);  // 세그멘테이션 오류

    printf("프로그램이 실행 중입니다. Ctrl+C를 누르거나 kill 명령을 보내보세요...\n");

    while (1) {
        // 무한 루프, 시그널 대기
        sleep(1);
    }

    return 0;
}
