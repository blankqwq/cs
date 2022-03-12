#include<stdio.h>

typedef struct{
    unsigned char a;
    unsigned char b;
}T;

void main(){
    int i = 420;
    T *temp = (T *)&i;
    printf("i = %d , sizeof i=%lu \n",i,sizeof(i));
    printf("a=%u b=%u c=%d \n",temp->a,temp->b,temp->a+(temp->b<<8));
}