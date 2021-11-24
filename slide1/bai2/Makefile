

HOME_DIR = .
C_DIR = $(HOME_DIR)/src
O_DIR = $(HOME_DIR)/obj
STATIC_DIR = $(HOME_DIR)/lib/static
CC = gcc

C_FILE = func.c main.c
O_FILE = $(patsubst %.c, $(O_DIR)/%.o, $(C_FILE))

$(O_DIR)/%.o: $(C_DIR)/%.c
	$(CC) -o $@ -c $^ -I inc/

static: $(O_FILE)
	ar rcs $(STATIC_DIR)/lib_mylib.a $(O_FILE)

link: $(O_FILE) static
	gcc obj/main.o -Llib/static -l_mylib.a -o bin/staitically-linker -I inc/

clear:
	rm -f obj/*.o
	rm -f lib/static/*.a