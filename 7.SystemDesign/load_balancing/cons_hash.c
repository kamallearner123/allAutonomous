#include <stdio.h>
#ifndef MAIN_PROG
#define MAIN main
#else
#define MAIN main_123
#endif

unsigned char get_hash1(char *data)
{
	return *data; 
}

int MAIN()
{
	int data = 100;

	printf("Result = %d\n", get_hash1((char *)&data));
}
