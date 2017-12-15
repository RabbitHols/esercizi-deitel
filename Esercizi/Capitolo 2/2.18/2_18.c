/**
Scrivete un programma che chieda all'utente di immettere due interi,
ottenga i numeri e visualizzi quello maggiore seguito dalle parole "is integer". 
Nel caso i numeri siano uguali, stampate il messaggio "There number are equal". 
Usate soltanto la forma a selezione singola dell'istruzione if 

**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

	int a = 0x0; int b = 0x0; int max = 0x0;

	printf("Dammi primo intero");
	scanf("%d", &a);

	printf("Dammi secondo intero");
	scanf("%d", &b);

	if( a == b){ printf("A e B sono uguali"); return 0; }

	a = (a > b) ? printf("A è maggiore di b. a = %d\n", a) : printf("B è maggiore di a. b = %d\n", a);

	return 0;
}