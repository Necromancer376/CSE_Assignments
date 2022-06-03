#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main()
{
	int old_socket, new_socket;
	char buff[1024];
	struct sockaddr_in server_addr;
	struct sockaddr_storage server_storage;
	socklen_t addr_size;

	old_socket = socket(PF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(7891);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	bind(old_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

	if(listen(old_socket, 5) == 0)
		printf("Listening\n");
	else
		printf("error\n");

	addr_size = sizeof(server_storage);
	new_socket = accept(old_socket, (struct sockaddr*) &server_storage, &addr_size);

	printf("msg: ");	
	scanf("%s", buff);
	send(new_socket, buff, 13, 0);

	return 0;
}
