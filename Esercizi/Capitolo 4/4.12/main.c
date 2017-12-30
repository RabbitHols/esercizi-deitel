/**
Scrivere un programma che calcoli e visualizzi la somma degli interi 
pari da 2 a 30
**/

#include <stdio.h>

int main(){

	int cnt;
	for(cnt = 0; cnt <= 30; cnt++){
		(!(cnt % 2 == 0) )? : printf("%d\n", cnt);

	}

	return 0;
}