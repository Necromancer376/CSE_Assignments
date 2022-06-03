#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define READER_SIZE 10
#define WRITER_SIZE 5


sem_t wrt;
pthread_mutex_t mutex;
int c = 1;
int n_reader = 0;


void *reader(void* r)
{
    pthread_mutex_lock(&mutex);
    n_reader++;
    if(n_reader == 1)
        sem_wait(&wrt);

    pthread_mutex_unlock(&mutex);
    printf("Reader\n\tid: %d, c: %d\n", *((int*)r), c);
    pthread_mutex_lock(&mutex);
    n_reader--;
    if(n_reader == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);

    return NULL;
}


void * writer(void* w)
{
    sem_wait(&wrt);
    c *= 2;
    printf("Writer\n\tid: %d, c: %d\n", *((int*)w), c);
    sem_post(&wrt);

    return NULL;
}


int main()
{
    pthread_t read[READER_SIZE], write[WRITER_SIZE];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    int arr[READER_SIZE];
    for(int i=0; i<READER_SIZE; i++)
        arr[i] = i+1;

    for(int i=0; i<READER_SIZE; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void*)&arr[i]);
    }

    for(int i=0; i<WRITER_SIZE; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void*)&arr[i]);
    }

    for(int i=0; i<READER_SIZE; i++)
    {
        pthread_join(read[i], NULL);
    }

    for(int i=0; i<WRITER_SIZE; i++)
    {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
}
