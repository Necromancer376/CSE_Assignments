#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024


int main() {
	int socket_fd;
	char buff[MAXLINE];
	char *msg = "Server msg";
	struct sockaddr_in server_addr, client_addr;
	

	if ( (socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&server_addr, 0, sizeof(server_addr));
	memset(&client_addr, 0, sizeof(client_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);
	
	if ( bind(socket_fd, (const struct sockaddr *)&server_addr,
			sizeof(server_addr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	len = sizeof(client_addr);

	n = recvfrom(socket_fd, (char *)buff, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &client_addr,
				&len);
	buff[n] = '\0';
	printf("Client : %s\n", buff);
	sendto(socket_fd, (const char *)msg, strlen(msg),
		MSG_CONFIRM, (const struct sockaddr *) &client_addr,
			len);

	printf("Message sent.\n");
	
	return 0;
}


// // Server side implementation of UDP client-server model
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <netinet/in.h>

// #define PORT	 8080
// #define MAXLINE 1024

// // Driver code
// int main() {
// 	int sockfd;
// 	char buffer[MAXLINE];
// 	char *hello = "Hello from server";
// 	struct sockaddr_in servaddr, cliaddr;
	
// 	// Creating socket file descriptor
// 	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
// 		perror("socket creation failed");
// 		exit(EXIT_FAILURE);
// 	}
	
// 	memset(&servaddr, 0, sizeof(servaddr));
// 	memset(&cliaddr, 0, sizeof(cliaddr));
	
// 	// Filling server information
// 	servaddr.sin_family = AF_INET; // IPv4
// 	servaddr.sin_addr.s_addr = INADDR_ANY;
// 	servaddr.sin_port = htons(PORT);
	
// 	// Bind the socket with the server address
// 	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
// 			sizeof(servaddr)) < 0 )
// 	{
// 		perror("bind failed");
// 		exit(EXIT_FAILURE);
// 	}
	
// 	int len, n;

// 	len = sizeof(cliaddr); //len is value/resuslt

// 	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);
// 	buffer[n] = '\0';
// 	printf("Client : %s\n", buffer);
// 	sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
// 	printf("Hello message sent.\n");
	
// 	return 0;
// }