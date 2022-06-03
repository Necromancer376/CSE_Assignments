#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>


#define MAX 10


sem_t barb_chair, wait_room, barb_sleep, cutting;
int is_done = 0;


void *customer(void *arg)
{
    int n = *(int*)arg;
    printf("%d arrived\n", n);
    sem_wait(&wait_room);
    printf("%d waiting\n", n);
    
    sem_wait(&barb_chair);
    sem_post(&wait_room);
    sem_post(&barb_sleep);
    printf("%d cutting\n", n);
    sem_wait(&cutting);
    sem_post(&barb_chair);
    printf("%d leaving\n", n);
}


void *barber(void *arg)
{
    while(!is_done)
    {
        printf("barber sleeping\n");
        sem_wait(&barb_sleep);

        if(!is_done)
        {
            printf("cutting\n");
            usleep(rand() % 50000);
            printf("not cutting\n");
            sem_post(&cutting);
        }
        else
        {
            printf("closed\n");
        }
    }
}


int main()
{
    pthread_t barb_id;
    pthread_t cust_id[MAX];

    int n_cust, n_chair;
    int num[MAX];

    printf("no of customers: ");
    scanf("%d", &n_cust);
    printf("no of chairs: ");
    scanf("%d", &n_chair);

    if(n_cust > MAX)
        exit(-1);

    for(int i=0; i<MAX; i++)
    {
        num[i] = i;
    }

    sem_init(&wait_room, 0, n_chair);
    sem_init(&barb_chair, 0, 1);
    sem_init(&barb_sleep, 0, 0);
    sem_init(&cutting, 0, 0);

    pthread_create(&barb_id, NULL, barber, NULL);
    for(int i=0; i<n_cust; i++)
    {
        pthread_create(&cust_id[i], NULL, customer, (void*)&num[i]);
        sleep(1);
    }

    for(int i=0; i<n_cust; i++)
    {
        pthread_join(cust_id[i], NULL);
        sleep(1);
    }
    is_done = 1;
    sem_post(&barb_sleep);
    pthread_join(barb_id, NULL);
}