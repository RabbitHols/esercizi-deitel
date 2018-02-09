/*

Scrivete un programma che simuli il lancio di una monetina. Per ogni lancio della monetino il
programma dovrà visualizzzare Testa o Croce. Lasciare che il programmare lanci la monetina 100 volte
e contare il numero di testa e croce. Il programma  dovrà usare la funzione flip.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();

int main(){
	
	srand(time(NULL));

	int testa = 0;
	int croce = 0;

	for(int cnt = 0; cnt < 10; cnt++){
		switch(flip()){
			case 0:
				printf("Testa\n");
				testa++;
				break;
			case 1:
				printf("Croce\n");
				croce++;
		}
	}

	printf("Numero testa: %d\nNumero croce: %d\n", testa, croce);

	return 0;
}

int flip(){

	int flip = rand() % 2;

}