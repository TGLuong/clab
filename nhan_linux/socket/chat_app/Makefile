
CC := gcc
PROJ_DIR := .
PROJ_NAME := chat_app
OUTPUT_PATH := .




server: server.c
	${CC} -o server server.c -pthread

client1: client1.c
	${CC} -o client1 client1.c -pthread


clear:
	rm -rf server client1
