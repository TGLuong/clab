

all: clean server client

server: server.c
	gcc -g -o server server.c -lrt
client: client.c
	gcc -g -o client client.c -lrt


clean: clean-client clean-server

clean-client:
	rm -rf client 
clean-server:
	rm -rf server
