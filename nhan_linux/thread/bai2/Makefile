
CC = gcc
rm_files = ct1 ct2 file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt

all: ct1.c ct2.c
	rm -rf ${rm_files}
	${CC} -o ct1 ct1.c
	${CC} -o ct2 ct2.c -pthread

clear:
	rm -rf ${rm_files}
