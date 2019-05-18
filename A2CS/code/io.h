//
//  io.h
//  Pa8
//
//  Created by Ian Ducrot  & François Xavier Hippert  on 15/03/2019.
//  Copyright © 2019 Ian Ducrot. All rights reserved.
//

#ifndef io_h
#define io_h

char *clean_string(char *dirtyString);
void read_file(float[]);
void log_stat(float* input, int numero_cycle);

#ifdef _WIN32
	#define getline(x,y,z) *x = malloc(sizeof(char) * 100); fgets(*x,100,z)
#endif // _WIN32

#ifdef __APPLE__
	#define PATH "/Users/leolellouche/Library/Mobile Documents/com~apple~CloudDocs/Cours/P@8/Pa8"
#else
	#define PATH "/home/pi/Documents/IOT_Projet/Final/Arduino2Pi/applicationlinuxarmv6hf"
				 
#endif




#endif /* io_h */
