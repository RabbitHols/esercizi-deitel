/**
Scrivere un programma che
a) visualizzi quoziente della divisione a b
b) visualizzi resto della divisione a b
c) scomporre il numero uno ad uno
**/

#include <stdio.h>
#include <stdlib.h>

void quoziente(int a, int b);
void resto(int a, int b);
void scomposizione(int n);

int main(int argc, char const *argv[])
{
	
	int num_1 = atoi(argv[1]);
	int num_2 = atoi(argv[2]);
	int num_3 = atoi(argv[3]);

	quoziente(num_1, num_2);
	resto(num_1, num_2);
	scomposizione(num_3);

	return 0;
}

void quoziente(int a, int b){
	printf("Il quoziente e':%d\n", a/b);
}

void resto(int a, int b){
	printf("Il resto e':%d\n", a%b);
}

void scomposizione(int n){

// Troviamo lunghezza del numero in decimali

	int nuovo_num = n;
	int cnt = 1;

	while(nuovo_num != 0){
		nuovo_num = nuovo_num / 10;
		cnt = (cnt * 10);
	}

	cnt = cnt / 10;


//	Scomponiamo il numero

	int num = n;
	int resto;
	int numeroScomposto;
	while(n != 0){
		resto = n % 10;
		n = n / 10;
		numeroScomposto = numeroScomposto + (cnt * resto);
		cnt = cnt / 10;
	}	

// rifacciamo il tutto per riordinarlo

	n = numeroScomposto;

	while(numeroScomposto != 0){
		resto = numeroScomposto % 10;
		numeroScomposto = numeroScomposto / 10;
		printf("%d ", resto);
	}	

	printf("\n");

}