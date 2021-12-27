#include "csapp.h"
#define N 5
sem_t w,mutex;
int readcnt,rc,wc=0;

void *write_t(void *arg){
    char *read_buf=(char *)arg;
    while (1)
    {
        /* code */
        sem_wait(&w);
        read_buf[wc]='w';
        printf("write:%d,%c\n",wc,read_buf[wc]);
        wc = (++wc)%(N);
        sem_post(&w);
    }
    
}
void *read_t(void *arg){
  while (1)
    {
        sem_wait(&mutex);
        /* code */
        readcnt++;
        if(readcnt==1){
            sem_wait(&w);
        }
        sem_post(&mutex);
        char *data = (char*)arg;
        if(data[rc]!=0){
            printf("get:%c,%d\n",data[rc],rc);
            data[rc]=0;
            rc = (++rc)%(N);
        }else{
            printf("continue! %c,current:%d\n",data[rc],rc);
        }
        sem_wait(&mutex);
        readcnt--;
        if(readcnt==0){
            sem_post(&w);
        }
        sem_post(&mutex);
    }
    
}


void main(){
    sem_init(&w,0,1);
    sem_init(&mutex,0,1);
    volatile char data[N]={};
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,read_t,(void *)data);
    pthread_create(&tid2,NULL,write_t,(void *)data);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("run");
}