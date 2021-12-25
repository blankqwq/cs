#include "csapp.h"

volatile int cnnt = 0;

void *add1(void *argv){
    int neither = *(int *)argv;
    for(int i=0;i<neither;i++){
        cnnt++;
    }
}

void main(int argc,char **argv){
    int neither;

    pthread_t tid1,tid2;

    neither = atoi(argv[1]);
    printf("get %d\n",neither);
    pthread_create(&tid1,NULL,add1,(void *)&neither);
    pthread_create(&tid2,NULL,add1,(void *)&neither);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    printf("res cnnt=%d\n",cnnt);
    if(cnnt!=(2*neither)){
        printf("error!\n");
    }else{
        printf("ok!\n");
    }
}