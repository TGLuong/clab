#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct SinhVien_Struct {
	char name[30];
	char class[5];
} SinhVien;

int read_line(int fd, char *des, int size) {
	char buffer;
	int index = 0;

	while (1) {
		read(fd, &buffer, 1);
		if (buffer == '\n' || buffer == -1 || index >= size - 1) {
			return index;
		} else {
			des[index] = buffer;
			index++;
		}
	}
}

int str_split(char *buffer, char **break_str, char delimiter) {
	int index = 0, num_str = 0;
	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == delimiter) {
			break_str[num_str][index] = '\0';
			index = 0;
			num_str++;
		} else {
			break_str[num_str][index] = buffer[i];
			index++;
		}
	}
}

int load_file(char src[30], SinhVien *sinhvien) {
	char buffer[100], **break_str;
	int sinhvien_fd, sv_len = 0, sv_index = 0;


	break_str = (char **) malloc(sizeof(char *) * 2);
	break_str[0] = malloc(sizeof(char) * 100);
	break_str[1] = malloc(sizeof(char) * 100);

	sinhvien_fd = open(src, O_RDONLY);
	while (1) {
		memset(buffer, 0, sizeof(buffer));
		if (read_line(sinhvien_fd, buffer, 100) == 0) break;
		
		memset(break_str[0], 0, sizeof(break_str[0]));
		memset(break_str[1], 0, sizeof(break_str[1]));

		str_split(buffer, break_str, '@');

		strncpy(sinhvien[sv_index].name, break_str[0], sizeof(break_str[0]));
		strncpy(sinhvien[sv_index].class, break_str[1], sizeof(break_str[1]));
		
		printf("%s - %s\n", sinhvien[0].name, sinhvien[0].class);


		sv_index++;

	}
	free(break_str[0]);
	free(break_str[1]);
	free(break_str);

	return sv_index;
}

void log_sinhvien(SinhVien *sinhvien, int sv_length) {
	printf("\n==========================================\n");
	printf("%-20s%-20s\n", "Name", "Class");
	for (int i = 0; i < sv_length; i++) {
		printf("%-20s%-20s\n", sinhvien[i].name, sinhvien[i].class);
	}
	printf("\n==========================================\n");
}


int main(int argc, char *argv[]) {
	SinhVien *sinhvien;
	int sv_length;

	sinhvien = (SinhVien *) malloc(sizeof(SinhVien) * 100);
	sv_length = load_file("sv_file.txt", sinhvien);
	printf("\ns= %s\n", sinhvien[0].class);
	log_sinhvien(sinhvien, sv_length);
	free(sinhvien);
}
