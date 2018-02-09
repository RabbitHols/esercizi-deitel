/*
Scrivere una funzione che prenda un valore intero e lo restituisca dopo aver
invertito le sue cifre. Per esempio, dato il numero 7631 la funzione deve restituire 1367
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int invert(int);

int main(){

	int num = 1234;

	printf("%d\n", invert(num));

	return 0;
}

int invert(int num){

	int inverted_num = 0;
	int resto = 0;
	int cnt = pow(10, floor(log10(abs(num))));

	while(num != 0){
		resto = num % 10;
		inverted_num += (resto * cnt);
		num /= 10;
		cnt /= 10;
	}

	return inverted_num;

}

