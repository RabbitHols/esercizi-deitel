/*

Stesso programma di prima solo risposte differenti

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	
	int a = rand() % 10;
	int b = rand() % 10;
	int risultato = 0;
	int risposta_corretta;
	int risposta_errata;
	
	do{

		risposta_corretta 	= rand() % 4;
		risposta_errata 	= rand() % 4;
		printf("Risolvimi la seguente moltiplicazione\n");
		printf("%d x %d\n", a,b);
		scanf("%d", &risultato);

		if(risultato == (a*b) ){
			switch(risposta_corretta){
				case 0: puts("Very good\n"); break;
				case 1: puts("Excellent\n"); break;
				case 2: puts("Nice Work\n"); break; 
				case 3: puts("Keep up the good work\n"); break; 
			}
		} else {
			switch(risposta_errata){
				case 0: puts("No. Please try again.\n"); break;
				case 1: puts("Wrong. Try once more\n"); break;
				case 2: puts("Don't give up\n"); break;
				case 3: puts("No. Keep trying\n"); break;
			}
		}

	}while(risultato != (a * b));

	return 0;
}