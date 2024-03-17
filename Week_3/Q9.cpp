#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define NUM_INCREMENTS 1000000

int counter = 0;
pthread_mutex_t mutex;

void *incrementCounter(void *arg) 
{
    for (int i = 0; i < NUM_INCREMENTS; i++) 
	{
        pthread_mutex_lock(&mutex); 
        counter++; 
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() 
{
    pthread_t threads[NUM_THREADS];

    
    if (pthread_mutex_init(&mutex, NULL) != 0) 
	{
        printf("Mutex initialization failed\n");
        return 1;
    }

    for (int i = 0; i < NUM_THREADS; i++) 
	{
        if (pthread_create(&threads[i], NULL, incrementCounter, NULL) != 0) 
		{
            printf("Thread creation failed\n");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) 
	{
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("Final counter value: %d\n", counter);

    return 0;
}

