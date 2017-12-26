/**
 * Scrivere un programma che legga in input tre valori di tipo float 
 * e determini e visualizzi se possono rappresentare i lati di un
 * triangolo
 *
 **/

#include <stdio.h>
#include <stdlib.h>

#define TRIANGOLO_IMPOSSIBILE(a,b,c) (a + b + c == 0)
#define TRIANGOLO_REGOLE(a,b,c) (a+b >= c)
int main(int argc, char const *argv[]){
	
	int a  = atoi(argv[1]);
	int b  = atoi(argv[2]);
	int c  = atoi(argv[3]);

	if(!TRIANGOLO_IMPOSSIBILE(a,b,c) && TRIANGOLO_REGOLE(a,b,c)){
		printf("Il triangolo è regolare\n");
	} else {
		printf("Spiacente il triangolo è impossibile");;
	}
	




	return 0;
}
