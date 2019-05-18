//
//  main.c
//  IOT
//
//  Created by Ian Ducrot on 15/03/2019.
//  Copyright © 2019 Ian DUCROT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "io.h"

int main(int argc, const char * argv[])
{
    int i = 0;

	for(i = 0; i < 40; i++)
	{
    float toRet[15];

    read_file(toRet); // toRet veut dire toReturn donc a envoyer

	log_stat(toRet, i); // Ecrit dans le fichier log_stats.csv


	}
	printf("end\n");
	return 0;
}
