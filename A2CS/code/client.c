/*
* client.c * *  Created on: 21 mars 2019
 *      Author: Renan 
 *		Collaborator: Aurelien
 */


/* Client code */
/* TODO : Modify to meet your need */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define PORT_NUMBER     5010
#define SERVER_ADDRESS  "10.3.3.80"
#define FILE_TO_SEND    "/home/pi/Documents/IOT_Projet/Final/Arduino2Pi/applicationlinuxarmv6hf/log_stats.csv"

int getFileDescriptor(struct stat *file_stat);
int sendfile(int client_socket, int fd, int *offset, int bufsiz, int file_size);

void client()
{
	int client_socket;
	ssize_t len;
	struct sockaddr_in remote_addr;
	char file_size[256];
	int fd;
	int remain_data = 0;
	int sent_bytes = 0;
	struct stat file_stat;
	int offset;
	/* Zeroing remote_addr struct */
	memset(&remote_addr, 0, sizeof(remote_addr));

	/* Construct remote_addr struct */
	remote_addr.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER_ADDRESS, &(remote_addr.sin_addr));
	remote_addr.sin_port = htons(PORT_NUMBER);

	/* Create client socket */
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1)
	{
		fprintf(stderr, "Error creating socket --> %s\n", strerror(errno));

		exit(EXIT_FAILURE);
	}

	/* Connect to the server */
	while (connect(client_socket, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
	{
		fprintf(stderr, "Error on connect --> %s\n", strerror(errno));

		//exit(EXIT_FAILURE);
		sleep(1);
	}
	//do{
	/* Getting the file */
	fd = getFileDescriptor(&file_stat);

	fprintf(stdout, "File Size: \n%ld bytes\n", file_stat.st_size);
	sprintf(file_size, "%ld", file_stat.st_size);
	/* Sending file size */
	len = send(client_socket, file_size, sizeof(file_size), 0);
	if (len < 0)
	{
		fprintf(stderr, "Error on sending greetings --> %s", strerror(errno));

		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "Server sent %ld bytes for the size\n", len);

	offset = 0;
	remain_data = file_stat.st_size;
	/* Sending file data */
	while (((sent_bytes = sendfile(client_socket, fd, &offset, BUFSIZ, file_stat.st_size)) > 0) && (remain_data > 0))
	{
		fprintf(stdout, "1. Server sent %d bytes from file's data, offset is now : %d and remaining data = %d\n", sent_bytes, offset, remain_data);
		remain_data -= sent_bytes;
		fprintf(stdout, "2. Server sent %d bytes from file's data, offset is now : %d and remaining data = %d\n", sent_bytes, offset, remain_data);
	}

	printf("File sent\n");
	//}while(1);
	close(client_socket);

}

int getFileDescriptor(struct stat *file_stat){
	int fd = 0;
	int exit_while=0;
	while(!exit_while){
		fd = open(FILE_TO_SEND, O_RDONLY);
		//no file or error while reading
		if (fd == -1 || fstat(fd, file_stat) < 0) {
			printf("Error when trying to reed the file");
			sleep(2000);
		}
		else{
			exit_while=1;
		}
	}
	return fd;
}

int sendfile(int client_socket, int fd, int *offset, int bufsiz, int file_size){
	if(*offset >= file_size)
		return 0;
	else {
		char *buffer = NULL;
		buffer = (char *) malloc(bufsiz);
		int endPoint = (*offset+bufsiz < file_size-*offset ) ? *offset+bufsiz : file_size;

		printf("\nfile reading log:\n");
		printf("\tbegin: %d\n", *offset);
		printf("\tend: %d\n", endPoint);
		printf("\tbuffer size: %d\n", bufsiz);
		printf("\tfile size: %d\n", file_size);

		//read(fd, *buffer) read method
		ssize_t result = read(fd, buffer,endPoint-*offset);
		printf("\tresult: %ld\n\n", result);
		//fwrite(buffer, result, 1, stdout);
		//printf("\n");
		*offset += result;
		send(client_socket, buffer, result,0);
		free(buffer);
		return result;
	}

}

long GetFileSize()
{
	long size;
	FILE *f;

	f = fopen(FILE_TO_SEND, "rb");
	if (f == NULL) return -1;
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fclose(f);

	return size;
}
