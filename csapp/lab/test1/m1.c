#include <stdio.h>
#include <string.h>
typedef struct 
{
    int max;
    int min;
    /* data */
}inner1;


typedef struct 
{
    int age;
    inner1 in;
    /* data */
} ts1;


int main(){
    ts1 t;
    ts1 *t1;
    t1=&t;
    printf("t1: %p sizeof: %lu\n",t1,sizeof(t));
    int a[3]={1,22,33};
    t1->age=10;
    t1->in.max=10;
    t1->in.min=0;
    printf("%d %d\n",t1->in.max,t1->in.min);
    memcpy(&t1->in.min,a+2,4);
    printf("%d %d\n",t1->in.max,t1->in.min);
    memcpy(&t.in.max,a,4);
    printf("%d %d\n",t1->in.max,t1->in.min);
    printf("inner addr:%p min:%p max:%p\n",&t1->in,&t1->in.max,&t1->in.min);
    printf("inner addr:%p min:%p max:%p",&t.in,&t.in.max,&t.in.min);
    return 0;
}