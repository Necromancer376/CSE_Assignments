#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>

#define COUNT 3

sem_t agnt;
sem_t smkr[3];

char* types[3] = {"m-t", "m-p", "t-p"};
int used[3] = {1, 1, 1};
sem_t push[3];
sem_t push_lock;


void *smoker(void *arg)
{
    int s_id = *(int*)arg;
    int type = s_id % 3;

    for(int i=0; i<COUNT; i++)
    {
        printf("Smoker\tid: %d, needs: %s\n", s_id, types[type]);

        sem_wait(&smkr[type]);
        printf("id: %d has 3 items\n", s_id);
        usleep(rand() % 50000);
        sem_post(&agnt);
        printf("id: %d process complete\n\n", s_id);
    }
}


void *pusher(void *arg)
{
    int id = *(int*)arg;

    for(int i=0; i<4*COUNT; ++i)
    {
        sem_wait(&push[id]);
        sem_wait(&push_lock);

        if(used[(id+1)%3])
        {
            used[(id+1)%3] = 0;
            sem_post(&smkr[(id+2)%3]);
        }
        else if(used[(id+2)%3])
        {
            used[(id+2)%3] = 0;
            sem_post(&smkr[(id+1)%3]);
        }
        else
        {
            used[id] = 1;
        }
        sem_post(&push_lock);
    }
}


void *agent(void *arg)
{
    int id = *(int*)arg;

    for(int i=0; i<2*COUNT; i++)
    {
        usleep(rand() % 200000);
        sem_wait(&agnt);
        sem_post(&push[id]);
        sem_post(&push[(id+1)%3]);
    }
}


int main()
{
    sem_init(&agnt, 0, 1);
    sem_init(&push_lock, 0, 1);
    for(int i=0;i<COUNT; i++)
    {
        sem_init(&smkr[i], 0, 0);
        sem_init(&push[i], 0, 0);
    }

    int smkr_id[2*COUNT];
    pthread_t smkr_threads[2*COUNT];

    int push_id[2*COUNT];
    pthread_t push_threads[2*COUNT];

    int agnt_id[2*COUNT];
    pthread_t agnt_threads[2*COUNT];

    for(int i=0; i<2*COUNT; i++)
    {
        smkr_id[i] = i;
        pthread_create(&smkr_threads[i], NULL, smoker, &smkr_id[i]);
    }

    for(int i=0; i<COUNT; i++)
    {
        push_id[i] = i;
        pthread_create(&push_threads[i], NULL, pusher, &push_id[i]);
    }

    for(int i=0; i<2*COUNT; i++)
    {
        push_id[i] = i;
        pthread_create(&agnt_threads[i], NULL, agent, &agnt_id[i]);
    }

    for(int i=0; i<2*COUNT; i++)
    {
        pthread_join(smkr_threads[i], NULL);
    }   
}
