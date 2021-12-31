// 分布计算

#include "csapp.h"
#define MAXTHREAD 3

#define UINTN unsigned long

sem_t mutex;
double max_id;
UINTN current[MAXTHREAD];
void *mutex_sum(void *arg){
    int id=*(long *)arg;
    UINTN start = id*max_id;
    UINTN end = start+max_id;;
    UINTN res = 0;
    for (UINTN i = start; i < end; i++)
    {
        // current[id]+=1;
        // 中间变量
        res++;
    }
    current[id] = res;
    // max speed
}

void main(int argc,char **argv){
    UINTN max = atoi(argv[1]);
    pthread_t t[MAXTHREAD];
    sem_init(&mutex,0,1);
    max_id = max/MAXTHREAD;
    int i;
    for(i=0;i<MAXTHREAD;i++){
        pthread_create(&t[i],NULL,mutex_sum,(void *)&i);
        pthread_join(t[i],NULL);
    }
    UINTN res=0;
    for (i = 0; i < MAXTHREAD; i++)
    {
        res+=current[i];
    }
    
    //打印结果
    printf("end=%lu\n",res);
}