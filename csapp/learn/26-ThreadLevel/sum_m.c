// 分布计算

#include "csapp.h"
#define MAXTHREAD 3

#define UINTN unsigned long

sem_t mutex;
double max_id;
UINTN current;
void *mutex_sum(void *arg){
    int id=*(long *)arg;
    UINTN start = id*max_id;
    UINTN end = start+max_id;;
    for (UINTN i = start; i < end; i++)
    {
        P(&mutex);
        current+=1;
        V(&mutex);
    }
}

void main(int argc,char **argv){
    UINTN max = atoi(argv[1]);
    pthread_t t[MAXTHREAD];
    current = 0;
    sem_init(&mutex,0,1);
    max_id = max/MAXTHREAD;
    for(int i=0;i<MAXTHREAD;i++){
        pthread_create(&t[i],NULL,mutex_sum,(void *)&i);
        pthread_join(t[i],NULL);
    }
    //打印结果
    printf("end=%lu\n",current);
}