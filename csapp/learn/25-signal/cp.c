#include "csapp.h"
#define N 5
sem_t w, mutex;
int readcnt, rc, wc = 0;

void *write_t(void *arg)
{
    int *data = (int *)arg;
    while (1)
    {
        /* code */
        sem_wait(&w);
        //write
        sleep(5);
        printf("write:%d\n", (*data)++);
        sem_post(&w);
    }
}
void *read_t(void *arg)
{
    int *data = (int *)arg;
    while (1)
    {
        sem_wait(&mutex);
        /* code */
        readcnt++;
        if (readcnt == 1)
        {
            sem_wait(&w);
        }
        sem_post(&mutex);

        //read
        sleep(3);
        printf("read:%d\n", (*data)--);
        sem_wait(&mutex);
        readcnt--;
        if (readcnt == 0)
        {
            sem_post(&w);
        }
        sem_post(&mutex);
    }
}

void main()
{
    sem_init(&w, 0, 1);
    sem_init(&mutex, 0, 1);
    volatile int data = 1;
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, read_t, (void *)&data);

    pthread_create(&tid2, NULL, write_t, (void *)&data);
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);
    //摆放位置有讲究
    printf("run");
}