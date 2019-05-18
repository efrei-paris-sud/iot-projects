/*
 * client.h
 *
 *  Created on: 21 mars 2019
 *     Author: Renan 
 *		Collaborator: Aurelien
 */

void client();
int sendfile(int peer_socket, int fd, int *offset, int bufsiz, int file_size);
