/**
Scrivere un programma che calcoli e visualizzi il prodotto
degli interi dispari da 1 a 15
**/

#include <stdio.h>
	
int main(){

	int cnt;
	int num = 0;

	for(cnt = 0; cnt <= 15; cnt++){
		num = (cnt % 2 == 0) ? num : num + cnt;
	}

	printf("%d\n", num);

	return 0;
}