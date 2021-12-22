#include "csapp.h"

void *thread(void *vargp){
    printf("hello world!i'm thread\n");
}

void main(){
    pthread_t id;
    // pid arguments 函数 参数
    pthread_create(&id,NULL,thread,NULL);
    // 等待id  返回值
    pthread_join(id,NULL);
    exit(0);

}