/*
Modificare il programma che avete scritto nell'esercizio 3.33
per visualizzare un quadrato vuoto:

Ex: 

* * * *
*     *
*     *
* * * *

*/

#include <stdio.h>

int main(){

	int lato;

	printf("Dammi lato quadrato: ");
	scanf("%d", &lato);

	int row, column;

	for(row = 0; row < lato; row++){

		for(column = 0; column < lato; column++){
			if(row == 0 || row == lato - 1){printf("\t*"); }
			else {	printf("\t+"); }
		}

		printf("\n\n\n");
	}


	return 0;
}