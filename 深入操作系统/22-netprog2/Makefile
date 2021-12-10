CC=gcc $(O_FILES) -o $(EXEC_FILE)
CFLAGS=-g -O1 -Wall
LDLIBS=-lpthread
O_FILES = $(C_FILES:.c=.o)

all: hostinfo echoclient echoserveri 

echoclient: echoclient.c csapp.h csapp.c
echoserveri: echoserveri.c echo.c csapp.h csapp.c
hostinfo: hostinfo.c csapp.h csapp.c

clean:
	rm -f *.o *~ *.exe hostinfo echoclient echoserveri csapp.o

