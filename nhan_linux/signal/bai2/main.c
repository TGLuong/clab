#include <signal.h>

int check = 1;

void int_handler(int sign) {
	check = 0;	
}

int main(int argc, char *argv[]) {
	signal(SIGINT, int_handler);
	while(check);
	return 0;
}
