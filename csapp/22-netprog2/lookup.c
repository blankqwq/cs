#include <csapp.h>

void main(int argc,char **argv){
    printf("get argc=%d,argv=%s \n",argc,*argv);
    struct addrinfo *result,target;
    
    int status = getaddrinfo(argv[2],SOCK_STREAM,&target,&result);
}