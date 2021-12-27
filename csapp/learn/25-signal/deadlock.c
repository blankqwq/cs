#include "csapp.h"

#define NITERS 100000
int cnt=0;
sem_t mutex[2];
void *count(void *arg){
    int i;
    int id = (int)arg;
    for(i=0;i<NITERS;i++){
        sem_wait(&mutex[id]); sem_wait(&mutex[1-id]);
        cnt++;
        printf("cnt:%d\n",cnt);
        sem_post(&mutex[id]); sem_post(&mutex[1-id]);
    }
}

void main(){
    pthread_t tid[2];

    sem_init(&mutex[0],0,1);
    sem_init(&mutex[1],0,1);

    pthread_create(&tid[0],NULL,count,(void *)1);
    pthread_create(&tid[1],NULL,count,(void *)0);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);

    printf("cnt:%d\n",cnt);
    exit(0);
}