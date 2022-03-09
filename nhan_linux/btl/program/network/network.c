#include <netdb.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void check_param(int argc, char *argv[]) {
	if (argc < 2) {
		printf("chua nhap lenh\n");
		exit(0);
	}
}

void list_netdevice(int argc, char *argv[]) {
	struct ifaddrs *addresses, *address;
	int status, family, family_size;
	char buffer[100];

	status = getifaddrs(&addresses);
	if (status == -1) {
		printf("khong the lay duoc dia chi\n");
		exit(0);
	}
	address = addresses;
	printf("%-15s%-15s%-15s\n", "device name", "protocol", "address");
	while (address) {
		family = address->ifa_addr->sa_family;
		family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
		memset(buffer, 0, sizeof(buffer));
		getnameinfo(address->ifa_addr, family_size, buffer, sizeof(buffer), 0, 0, NI_NUMERICHOST);

		printf("%-15s%-15s%-15s\n", address->ifa_name, family == AF_INET ? "IPv_4" : "IPv_6", buffer);
		address = address->ifa_next;
	}
	freeifaddrs(addresses);

}


int main(int argc, char *argv[]) {
	check_param(argc, argv);

	if (strcmp(argv[1], "list") == 0) {
		list_netdevice(argc, argv);
	}
	return 0;
}
