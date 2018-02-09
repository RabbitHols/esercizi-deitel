/*

Dopo aver digitato le 10 risposte verificare la percentuale di quelle corrette se è minore del 75%
far apparire il seguente messaggio:
"Please ask you istructor for extra help"

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int a;
	int b;
	int risultato;
	int risposte_sbagliate;
	float perc_sbagliate;
	risposte_sbagliate = 0;


	int cnt = 1;
	for(int cont = 1; cont <= 10; cont++){		
		a = rand() % 10;
		b = rand() % 10;
		do{
			puts("Scrivimi il prodotto della seguente moltiplicazione\n");
			printf("%d x %d\n", a,b);
			scanf("%d", &risultato);

			if(risultato != (a * b)){
				risposte_sbagliate++;	
			}
		}while(risultato != (a*b));

	} // Fine for

	perc_sbagliate = (float)risposte_sbagliate / 10;

	if(perc_sbagliate >= 0.75){
		puts("Please ask you istructor for extra help");
	}

	return 0;
}