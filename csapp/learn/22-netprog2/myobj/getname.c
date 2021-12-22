#include "csapp.h"
#include <errno.h>
int open_listenfd2(char *port)
{
    struct addrinfo *p, *listp, hints;
    char buf[MAXLINE];
    int rc, flags;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICSERV;
    int status = getaddrinfo(NULL, port, &hints, &listp);
    printf("start listen:...%d,%s\n",status,gai_strerror(status));
    int listenfd;
    int optval = 1;
    for (p = listp; p; p = p->ai_next)
    {
        if ((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
        {
            printf("next ... %s\n",gai_strerror(listenfd));
            continue;
        }
        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
        {
            printf("get fd=%d\n",listenfd);
            break;
        }
        close(listenfd);
    }
    if (!p)
    {
        fprintf(stderr, "listen erroor :%s\n", gai_strerror(rc));
        exit(-1);
    }
    return listenfd;
}


void main(int argc, char **argv)
{
    printf("get argc=%d,argv=%s \n", argc, argv[1]);
    // ip反解析
    if (argc==1)
    {
        perror("err:");
        exit(1);
    }
    
    open_listenfd2(argv[1]);

}