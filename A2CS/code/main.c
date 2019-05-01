//
//  main.c
//  IOT
//
//  Created by Ian Ducrot & Elise Auvray on 15/03/2019.
//  Copyright © 2019 Ian DUCROT. All rights reserved.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "io.h"
#include "md5.h"

char etat_lock()
{
	FILE *lockFile;
	char lock;
	
	lockFile = fopen(PATH"/merged.lock", "r");
	fread(&lock, 1, 1, lockFile);
	printf("etat du lock : %c\n", lock);
	fclose(lockFile);
	
	return lock;
}

void lock_file()
{
	FILE *lockFile;

	lockFile = fopen(PATH"/merged.lock", "w+");
	fprintf(lockFile, "%d", 1);
	fclose(lockFile);
	printf("Fichier lock\n");
	etat_lock();
}

void unlock_file()
{
	FILE *lockFile;

	lockFile = fopen(PATH"/merged.lock", "w+");
	fprintf(lockFile, "%d", 0);
	fclose(lockFile);
	printf("Fichier unlock\n");
}


void wait_until_unlock()
{
	char lock = ' ';
	
	do
	{
		if (lock != ' ')
			usleep(10000);
		lock = etat_lock();
	} while (lock != '0');
	
	lock_file();
	
}



int main(int argc, const char * argv[])
{
    int i = 0;
    
    //MD5 Algo
    char *new_md5;
	char *old_md5;

	old_md5 = strdup("00");
	new_md5 = NULL;
	

	for(i = 0; i < 2700; i++)
	{
		printf("BOUCLE\n");
		new_md5 = sum(PATH"/merged.txt");
		//printf("new md5 : %s \n", new_md5);
		//printf("old md5 : %s \n", old_md5);
	    if (strcmp(new_md5, old_md5) != 0)
        {
			wait_until_unlock();
			printf("Nouvelles donnees : md5 change");
			sleep(2);
            free(old_md5);
            old_md5 = strdup(new_md5);
            
			float toRet[12];
			
			read_file(toRet); // toRet veut dire toReturn donc a envoyer

			log_stat(toRet, i); // Ecrit dans le fichier log_stats.csv
			
			client();
			unlock_file();
		}
		free(new_md5);
        new_md5 = NULL;

		usleep(500000);
	}
	printf("end\n");
	return 0;
}
