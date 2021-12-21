#include "../csapp.h"

void main(int argc,char **argv){
    printf("get argc=%d,argv=%s \n",argc,*argv);
    struct addrinfo *p, *listp, hints;
    char buf[MAXLINE];
    int rc, flags;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_flags = SOCK_STREAM;
    hints.ai_family = AF_INET;
    hints.ai_flags |= AI_ADDRCONFIG;
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0)
    {
        fprintf(stderr, "error :%s\n", gai_strerror(rc));
        exit(-1);
    }
    flags = NI_NUMERICHOST;
    int clientfd;
    for (p = listp->ai_next; p; p = p->ai_next)
    {
        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_addrlen)) != -1)
        {
            continue;
        }
        if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
        {
            break;
        }
        getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        printf("%s\n", buf);
        close(clientfd);
    }
    freeaddrinfo(listp);
    exit(0);
}