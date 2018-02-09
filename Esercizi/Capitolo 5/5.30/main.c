/*
Scrivete una funzione qualityPoints che prenda in input la media di uno studente e restituisca

4 se la media è tra 90 e 100
3 tra 80 e 89
2 tra 70 e 79
1 tra 60-69  
0 in caso minore di 60

*/

#include <stdio.h>

int qualityPoints(int);

int main(){

	printf("%d", qualityPoints(91));

	return 0;
}

int qualityPoints(int media){

	if(media >= 90 && media <= 100){ return 4; }
	if(media >= 80 && media <= 89 ){ return 3; }
	if(media >= 70 && media <= 79 ){ return 2; }
	if(media >= 60 && media <= 69 ){ return 1; }
	if(media < 60){ return 0; }

	return -1;

	return 0;
}