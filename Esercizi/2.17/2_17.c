/**

2_17

Scrivere un programma che visualizzi i numeri da 1 a 4 sulla stessa riga. Scrite il programma
utilizzando i seguenti metodi:

a) Usando una istruzione printf senza specifiche di conversione
b) Usando una istruzione printf con quattro specifiche di conversione
c) Usando quattro istruzioni printf

**/

#include <stdio.h>

void a(){
	printf("1 2 3 4 \n");
}

void b(){
	printf("%d %d %d %d\n", 1,2,3,4);
}

void c(){
	printf("1 ");
	printf("2 ");
	printf("3 ");
	printf("4\n");
}
int main(int argc, char const *argv[])
{

	a();
	b();
	c();

	return 0;
}