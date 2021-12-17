#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void flush_stdin();

typedef struct SinhVien_struct {
    char name[30];
    int age;
    char className[20];
} SinhVien;
SinhVien sinhVien;


pthread_t thread_1, thread_2, thread_3;
pthread_mutex_t mutex_1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t sign_1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t sign_2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t sign_3 = PTHREAD_COND_INITIALIZER;
int count;

void *thread_handler_1(void *param) {
    pthread_detach(pthread_self());
    while (1)
    {
        pthread_mutex_lock(&mutex_1);
        printf("name : ");
        fgets(sinhVien.name, sizeof(sinhVien.name), stdin);
        sinhVien.name[strcspn(sinhVien.name, "\n")] = 0;
        printf("age : ");
        scanf("%d", &sinhVien.age);
        flush_stdin();
        printf("class name : ");
        fgets(sinhVien.className, sizeof(sinhVien.className), stdin);
        sinhVien.className[strcspn(sinhVien.className, "\n")] = 0;
        pthread_cond_signal(&sign_2);
        pthread_cond_wait(&sign_1, &mutex_1);
        pthread_mutex_unlock(&mutex_1);
    }
    
}

void *thread_handler_2(void *param) {
    pthread_detach(pthread_self());
    while(1) {
        pthread_mutex_lock(&mutex_1);
        pthread_cond_wait(&sign_2, &mutex_1);
        int file = open("./data.bin", O_CREAT|O_WRONLY, S_IRWXU);
        printf("size of sinh vien : %ld", sizeof(sinhVien));
        write(file, &sinhVien, sizeof(sinhVien));
        close(file);
        pthread_cond_signal(&sign_3);
        pthread_mutex_unlock(&mutex_1);
    }
}

void *thread_handler_3(void *param) {
    while(1) {
        pthread_mutex_lock(&mutex_1);
        pthread_cond_wait(&sign_3, &mutex_1);
        int file = open("./data.bin", O_RDONLY);
        SinhVien sv;
        read(file, &sv, sizeof(sv));
        printf("\nthong tin sinh vien la : \n");
        printf("name : %s\n", sv.name);
        printf("age : %d\n", sv.age);
        printf("class name : %s\n", sv.className);
        pthread_cond_signal(&sign_1);
        pthread_mutex_unlock(&mutex_1);
    }
}

void flush_stdin() {
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

int main(int argc, char *argv[]) {
    pthread_create(&thread_3, NULL, &thread_handler_3, NULL);
    pthread_create(&thread_2, NULL, &thread_handler_2, NULL);
    pthread_create(&thread_1, NULL, &thread_handler_1, NULL);
    while(1);
}