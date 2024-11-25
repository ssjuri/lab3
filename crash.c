#include <stdio.h>

int main() {
    int *ptr = NULL;  // NULL 포인터 생성
    *ptr = 10;        // NULL 포인터 접근 (크래시 발생)
    return 0;
}

