#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define BUF_SIZE 3
#define MAX 2

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BUF_SIZE];
pthread_mutex_t mutex;


void *producer(void *p)
{
    int item;
    for(int i=0; i<MAX; i++)
    {
        item = rand()%10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer\n\tid:%d, item:%d index:%d\n", *((int*)p), buffer[in], in);
        in = (in+1)%BUF_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    return NULL;
}


void *consumer(void *c)
{
    for(int i=0; i<MAX; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer\n\tid:%d, item:%d index:%d\n", *((int*)c), item, out);
        out = (out+1)%BUF_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return NULL;
}


int main()
{
    pthread_t prod[BUF_SIZE], cons[BUF_SIZE];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUF_SIZE);
    sem_init(&full, 0, 0);

    int a[BUF_SIZE];
    for(int i=0; i<BUF_SIZE; i++)
        a[i] = i+1;

    for(int i=0; i<BUF_SIZE; i++)
    {
        pthread_create(&prod[i], NULL, (void *)producer, (void *)&a[i]); 
    }

    for(int i=0; i<BUF_SIZE; i++)
    {
        pthread_create(&cons[i], NULL, (void *)consumer, (void *)&a[i]); 
    }

    for(int i=0; i<BUF_SIZE; i++)
    {
        pthread_join(prod[i], NULL);
    }

    for(int i=0; i<BUF_SIZE; i++)
    {
        pthread_join(cons[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}
