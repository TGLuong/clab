
CC := g++
all: clean cons prod
INC_DIR := inc/
CFLAGS := -lmosquitto -pthread

cons: cons.cc
	${CC} -o cons cons.cc -I ${INC_DIR} ${CFLAGS}
prod: prod.cc
	${CC} -o prod prod.cc -I ${INC_DIR} ${CFLAGS}

clean:
	rm -rf cons prod
