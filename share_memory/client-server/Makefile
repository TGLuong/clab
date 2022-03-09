
CC = gcc

all: server client

server: server.c
	${CC} -ltr -o server server.c

client: client.c
	${CC} -ltr -o client client.c

clear:
	rm -rf client server
