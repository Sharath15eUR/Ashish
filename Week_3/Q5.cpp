#include <stdio.h>
#include <pthread.h>

void *printHello(void *arg) {
    printf("Hello ");
    pthread_exit(NULL);
}

void *printWorld(void *arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid1, tid2; // Thread IDs

    
    if(pthread_create(&tid1, NULL, printHello, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

   
    pthread_join(tid1, NULL);

    
    if(pthread_create(&tid2, NULL, printWorld, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

   
    pthread_join(tid2, NULL);

    return 0;
}

