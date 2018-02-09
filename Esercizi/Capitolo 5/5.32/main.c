/*

Utilizzate rand per produrre due interi positivi di una cifra. Dovete quindi visualizzare una domanda:
Quanto fa 6 * 7?
In seguito lo studente digiterà la risposta. Il vostro programma controllerà la risposta e se
sarà giusta visualizzare "Giusto" altrimenti "Sbagliato" lasciare che tenti la risposta finquando non
risponde correttamente.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int a = rand() % 10;
	int b = rand() % 10;

	int risultato;

	do{
		printf("Dammi risultato della seguente moltiplicazione\n");
		printf("%d x %d\n", a,b);
		scanf("%d", &risultato);
	} while(risultato != ( a * b) );


	return 0;
}