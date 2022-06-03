#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main()
{
	int client_socket;
	char buff[1024];
	struct sockaddr_in server_addr;
	socklen_t addr_size;

	client_socket = socket(PF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(7891);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	addr_size = sizeof(server_addr);
	
	connect(client_socket, (struct sockaddr *) &server_addr, addr_size);
	recv(client_socket, buff, 1024, 0);

	printf("%s\n", buff);

	return 0;
}




// void error(char* msg)
// {
// 	perror(msg);
// 	exit(0);
// }


// int main(int argc, char* argv[])
// {
// 	int socket_fd, port_num, n;
// 	struct sockaddr_in server_addr;
// 	struct hostent *server;
// 	char buff[256];

// 	if(argc < 3)
// 	{
// 		fprintf(stderr, "hostname port %s\n", argv[0]);
// 		exit(0);
// 	}

// 	port_num = atoi(argv[2]);
// 	socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

// 	if(socket_fd == 0)
// 	{
// 		error("error opening socket\n");
// 	}

// 	server = gethostbyname(argv[1]);
// 	if(server == NULL)
// 	{
// 		fprintf(stderr, "ERROR, no such host\n");
// 		exit(0);
// 	}

// 	bzero((char*)&server_addr, sizeof(server_addr));
// 	server_addr.sin_family = AF_INET;
// 	bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
// 	server_addr.sin_port = htons(port_num);

// 	if(connect(socket_fd, &server_addr,sizeof(server_addr)) < 0)
// 		error("ERROR connecting");

// 	printf("enter msg: ");
// 	bzero(buff,256);
// 	fgets(buff,255, stdin);

// 	n = send(socket_fd, buff, strlen(buff), 0);
// }