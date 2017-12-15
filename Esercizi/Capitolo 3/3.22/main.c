/*
Scrivere un programma che dimostri la differenza tra il predecremento e il postdecremento
utilizzando l'operatore di decremento --
*/

#include <stdio.h>

int main(){

	int a = 1;
	int b = 1;

	printf("%d\n", a--);
	printf("%d\n", a);

	printf("\n\n");

	printf("%d\n", --b);
	printf("%d\n", b);


	return 0;
}