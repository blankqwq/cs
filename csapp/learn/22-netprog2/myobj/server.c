#include "../csapp.h"

int openListenFd(char *port)
{
    struct addrinfo *p, *listp, hints;
    char buf[MAXLINE];
    int rc, flags;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICSERV;
    int status = getaddrinfo(NULL, port, &hints, &listp);
    if (status<0)
    {
        printf("start listen:...%d,%s\n", status, gai_strerror(status));
        exit(-1);
    }
    
    
    int listenfd;
    int optval = 1;
    for (p = listp; p; p = p->ai_next)
    {
        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
        {
            printf("next ... %s\n", gai_strerror(listenfd));
            continue;
        }
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
        {
            printf("get fd=%d\n", listenfd);
            break;
        }
        //监听失败
        close(listenfd);
    }
    if (!p)
        return -1;
    //make listening
    if(listen(listenfd,LISTENQ)<0){
        close(listenfd);
        return -1;
    }
    return listenfd;
}

char *echo(int clientfd)
{
    while (fread(clientfd,N,))
    {
        /* code */
    }
    
}

void main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("please use by:./server <port>");
        exit(1);
    }
    int listenfd = openListenFd(argv[1]);
    if (listenfd < 0)
    {
        fprintf(stderr, "error:%s", gai_strerror(listenfd));
        exit(1);
    }
    int clientlen,connfd;
    struct sockaddr_storage clientaddr;
    char client_hostname[MAXLINE],client_port[MAXLINE];
    // 获取数据
    while (1)
    {
        // 获取
        clientlen = sizeof(struct sockaddr_storage);
        printf("connfd=%d,listenfd=%d\n",connfd,listenfd);
        connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
        printf("connfd=%d,listenfd=%d\n",connfd,listenfd);
        getnameinfo((SA *)&clientaddr, clientlen, client_hostname, MAXLINE,
                    client_port, MAXLINE, 0);
        printf("recv host:%s,port:%s\n",client_hostname,client_port);
        echo(connfd);
        close(connfd);
    }
}