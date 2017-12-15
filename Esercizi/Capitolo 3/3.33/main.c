/*
Scrivere un programma che legga in input il lato di un programma e quindi lo disegni 
utilizzando degli asterischi. Il vero programma dovrà con tutti i quadrati di dimensioni
dei lati comprese tra 1 e 20. Per esempio la dimensione è 4 deve visualizzare:

	* * * *
	* * * *
	* * * *
	* * * *
*/

#include <stdio.h>

int main(){

	int lato;

	printf("Dammi lato quadrato: ");
	scanf("%d", &lato);
	printf("\n");
	
	int rowCont, columnCont;

	for(rowCont = 0; rowCont < lato; rowCont++){
		for(columnCont = 0; columnCont < lato; columnCont++){
			printf("\t*");
		}

		printf("\n\n\n");
	}

	return 0;
}