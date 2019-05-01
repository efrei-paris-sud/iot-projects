//
//  io.c
//  IOT
//
//  Created by Ian Ducrot  & François Xavier Hippert on 15/03/2019.
//  Copyright © 2019 Ian DUCROT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"
#include "client.h"


char *clean_string(char *dirtyString)
{
    int i = 0;

	while((dirtyString[i] != '=') && (dirtyString[i] != ':') && (dirtyString[i] != '\0'))
	{
		//printf("%c", dirtyString[i]);
        dirtyString[i] = ' ';
        i++;
	}
	dirtyString[i] = ' ';

	return dirtyString;
}

int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}



void read_file(float toRet[])
{
	//printf("Debut du readfile");
	char *tmp = NULL;
	size_t	*toRead = NULL;


	FILE *txt = NULL;
	//system("pwd  ");

	//test 1
	/*
	system("pwd");
	system("ls");
	printf("%s\n" PATH"/merged.txt");
	* */
	txt = fopen(PATH"/merged.txt", "r");
	/*
	system("pwd");
	system("ls");
	printf("%s\n" PATH"/info2.txt");
	txt = fopen(PATH"/info2.txt", "r");
	*/

	toRead = malloc(sizeof(size_t));

    //DATE
	*toRead = 100;
	getline(&tmp,toRead,txt);

    //Begin symbol
	*toRead = 100;
	getline(&tmp,toRead,txt);

	//Accelerometer comment
	*toRead = 100;
	getline(&tmp,toRead,txt);
	//Accelerometer comment

	//Values
	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[0] = atof(clean_string(tmp));


	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[1] = atoi(clean_string(tmp));

	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[2] = atoi(clean_string(tmp));
	//End of values


	//Temp comment
	*toRead = 100;
	getline(&tmp,toRead,txt);
	//Temp comment

    //Temp value
	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[3] = atof(tmp);
	//End of value
	
	//Humidity value
	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[4] = atof(tmp);
	//End of value


	// Multichannel Gas Comment
	*toRead = 100;
	getline(&tmp, toRead, txt);
	// Multichannel Gas Comment

	// Values
	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[5] = atof(clean_string(tmp));

	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[6] = atof(clean_string(tmp));

	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[7] = atof(clean_string(tmp));

	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[8] = atof(clean_string(tmp));

	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[9] = atof(clean_string(tmp));
	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[10] = atof(clean_string(tmp));

	*toRead = 100;
	getline(&tmp, toRead, txt);
	toRet[11] = atof(clean_string(tmp));

	
	//END symbol
	//*toRead = 100;
	//getline(&tmp,toRead,txt);

	fclose(txt);
	free(toRead);
	free(tmp);
	toRead = NULL;
	tmp = NULL;

}


void log_stat(float* input, int numero_cycle)
{

		char buffer[50];
		FILE	*exist = NULL;
		FILE	*csv = NULL;
		exist = fopen(PATH"/log_stats.csv", "r+");

		if (exist == NULL)
		{
			csv = fopen(PATH"/log_stats.csv", "a");
			fprintf(csv, "date;gyro.x;gyro.y;gyro.z;out_temp;humidity;NH3;CO;NO2;C3H8;CH4;H2;C2H5OH\n");
			fclose(csv);
		}
		else
		{
		    csv = fopen(PATH"/log_stats.csv", "a");
            fclose(exist);
            exist = NULL;
		}




		time_t t = time(NULL);
		strftime(buffer, 50, "%F %T", localtime(&t));


		fprintf(csv, "%s;", buffer);
		fprintf(csv, "%f;", input[0]);
		fprintf(csv, "%f;", input[1]);
		fprintf(csv, "%f;", input[2]);
		fprintf(csv, "%f;", input[3]);
		fprintf(csv, "%f;", input[4]);
		fprintf(csv, "%f;", input[5]);
		fprintf(csv, "%f;", input[6]);
		fprintf(csv, "%f;", input[7]);
		fprintf(csv, "%f;", input[8]);
		fprintf(csv, "%f;", input[9]);
		fprintf(csv, "%f;", input[10]);
		fprintf(csv, "%f\n", input[11]);
		
		fclose(csv);
		
		/*
		printf("Client fini\n");
		
		int status; 
		printf("Taille du fichier : %d", fsize(csv));
		if (fsize(csv) >= 8000) {
			fclose(csv);
			status = remove(PATH"/log_stats.csv");
 
			  if (status == 0)
				printf("File deleted successfully.\n");
			  else
			  {
				printf("Unable to delete the file\n");
				perror("Following error occurred");
			  }
		}*/
		

}
