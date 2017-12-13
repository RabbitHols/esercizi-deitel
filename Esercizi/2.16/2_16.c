/**
Scrivere un programma che chieda all'utente di immettere due interi, ottenga i numeri dall'utente e visualizzi la loro somma, 
prodotto, differenza, quoziente e resto
**/

#include <stdio.h>

int somma(int, int);
int prodotto(int, int);
int differenza(int, int);
double quoziente(int, int);

int main(int argc, char const *argv[])
{

	int a = 0x0;
	int b = 0x0;

	printf("Dammi primo intero\n");
	scanf("%d", &a);
	printf("Dammi secondo intero\n");
	scanf("%d", &b);

	printf("### LA SOMMA E' ### %d\n",somma(a,b));

	printf("\n### IL PRODOTTO E' ### %d\n", prodotto(a,b));

	printf("\n### LA DIFFERENZA E' ### %d\n", differenza(a,b));

	printf("\n### IL QUOZIENTE E' ### %.2f\n", quoziente(a,b));
	
	return 0;
}

int somma(int a, int b){

	return a + b;

}

int prodotto(int a, int b){

	return a * b;
}

int differenza(int a, int b){

	return a - b;
}

double quoziente(int a, int b){
	return  (double)a / (double)b;
}