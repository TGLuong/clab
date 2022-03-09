

CC := gcc

ROOT_DIR := .
OBJ_DIR := $(ROOT_DIR)/obj
SRC_DIR := $(ROOT_DIR)/src

C_FILE := hello1.c hello2.c main.c
OBJ_FILE := $(patsubst %.c, $(SRC_DIR)/%.o, $(C_FILE))


%.o: %.c
	gcc 

make_obj: $(OBJ_FILE)
	
