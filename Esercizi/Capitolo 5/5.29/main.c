/*

Il massimo comun divisore (MCD) di due interi è l'intero più grande che possa dividere 
esattamente ognungo dei due numeri. Scrivere una funzionde gcd che restituisca il CMD
di 2 numeri. 

*/

#include <stdio.h>

int mcd(int, int);

int main(){

	int num_1 = 24;
	int num_2 = 36;

	printf("%d\n", mcd(num_1, num_2));

	return 0;
}

int mcd(int a, int b){

    while(b) b ^= a ^= b ^= a %= b;

	return a;
}