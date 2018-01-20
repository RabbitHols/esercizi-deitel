/*
 * Per ognuno dei seguenti gruppi di interi. scrivere una signola istruzione che visualizzi
 * un numero casuale tratto dal gruppo.
 * a) 2,4,6,8,10
 * b) 3,5,7,9,11
 * c) 6,10,14,18,22
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	srand(time(NULL));


	int nc_U = 2 * (1 + rand() % 5);
	printf("%d\n", nc_U);
	
	int nc_D = 1 + 2 * (1 + rand() % 5);
	printf("%d\n", nc_D);
	
	int nc_T = 2 + 4 * (1 + rand() % 5);
	printf("%d\n", nc_T);
	
	return 0;
}
