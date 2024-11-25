#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>  // wait 함수 사용을 위한 헤더 추가

#define SHM_SIZE 1024  // 공유 메모리 크기
#define SEM_KEY 1234   // 세마포어 키

// 공유 메모리 구조체
struct shared_memory {
    char buffer[SHM_SIZE];
    size_t size;  // 데이터 크기
};

// 세마포어 연산을 위한 구조체
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

// 세마포어 연산 함수
void semaphore_wait(int semid) {
    struct sembuf sops = {0, -1, 0};
    if (semop(semid, &sops, 1) == -1) {
        perror("semop wait");
        exit(1);
    }
}

void semaphore_signal(int semid) {
    struct sembuf sops = {0, 1, 0};
    if (semop(semid, &sops, 1) == -1) {
        perror("semop signal");
        exit(1);
    }
}

// 파일을 읽어서 공유 메모리에 저장하는 부모 프로세스
void parent_process(int semid, struct shared_memory *shm) {
    int fd = open("source.txt", O_RDONLY);
    if (fd == -1) {
        perror("open source.txt");
        exit(1);
    }

    // 파일 내용 읽기
    ssize_t bytes_read = read(fd, shm->buffer, SHM_SIZE);
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }
    shm->size = bytes_read;

    // 세마포어로 자식 프로세스에게 데이터 준비 완료 신호 보내기
    semaphore_signal(semid);

    close(fd);
}

// 파일을 공유 메모리에서 읽어 다른 파일에 쓰는 자식 프로세스
void child_process(int semid, struct shared_memory *shm) {
    // 세마포어로 부모 프로세스가 파일을 읽을 때까지 기다리기
    semaphore_wait(semid);

    int fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open destination.txt");
        exit(1);
    }

    // 공유 메모리에서 데이터 읽어서 파일에 쓰기
    ssize_t bytes_written = write(fd, shm->buffer, shm->size);
    if (bytes_written == -1) {
        perror("write");
        exit(1);
    }

    close(fd);
}

int main() {
    // 공유 메모리 생성
    key_t key = ftok("file_copy.c", 65);
    int shm_id = shmget(key, sizeof(struct shared_memory), 0666 | IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // 공유 메모리 연결
    struct shared_memory *shm = (struct shared_memory *)shmat(shm_id, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // 세마포어 생성
    int semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // 세마포어 초기화
    union semun sem_union;
    sem_union.val = 0; // 부모 프로세스가 데이터를 먼저 읽을 수 있도록 세마포어를 0으로 설정
    if (semctl(semid, 0, SETVAL, sem_union) == -1) {
        perror("semctl");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        // 자식 프로세스 (파일에 쓰기)
        child_process(semid, shm);
    } else if (pid > 0) {
        // 부모 프로세스 (파일 읽기)
        parent_process(semid, shm);
        wait(NULL);  // 자식 프로세스가 종료될 때까지 기다리기
    } else {
        perror("fork");
        exit(1);
    }

    // 공유 메모리 분리
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // 공유 메모리 삭제
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // 세마포어 삭제
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl IPC_RMID");
        exit(1);
    }

    return 0;
}
