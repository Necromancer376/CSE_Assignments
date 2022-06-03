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
	char *msg = "Client msg";
	struct sockaddr_in	 server_addr;

	if ( (socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	
	int n, len;
	
	sendto(socket_fd, (const char *)msg, strlen(msg),
		MSG_CONFIRM, (const struct sockaddr *) &server_addr,
			sizeof(server_addr));
	printf("Message sent.\n");
		
	n = recvfrom(socket_fd, (char *)buff, MAXLINE,
				MSG_WAITALL, (struct sockaddr *) &server_addr,
				&len);
	buff[n] = '\0';
	printf("Server : %s\n", buff);

	close(socket_fd);
	return 0;
}


// // Client side implementation of UDP client-server model
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
// 	char *hello = "Hello from client";
// 	struct sockaddr_in	 servaddr;

// 	// Creating socket file descriptor
// 	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
// 		perror("socket creation failed");
// 		exit(EXIT_FAILURE);
// 	}

// 	memset(&servaddr, 0, sizeof(servaddr));
	
// 	// Filling server information
// 	servaddr.sin_family = AF_INET;
// 	servaddr.sin_port = htons(PORT);
// 	servaddr.sin_addr.s_addr = INADDR_ANY;
	
// 	int n, len;
	
// 	sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
// 	printf("Hello message sent.\n");
		
// 	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
// 	buffer[n] = '\0';
// 	printf("Server : %s\n", buffer);

// 	close(sockfd);
// 	return 0;
// }
