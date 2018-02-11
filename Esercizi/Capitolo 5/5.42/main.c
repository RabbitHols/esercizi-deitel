/*
Massimo comun divisore con la ricorsione
*/

#include <stdio.h>

int gcd(int x, int y);
int mcd(int x, int y);

int main(){

	printf(" Iterativo -> %d\n", mcd(48,24) );
	printf(" Recursvio -> %d\n", mcd(24,48) );

	return 0;
}

int gcd(int x, int y){
	
	return (y == 0) ? x : gcd(y, x % y);

}

int mcd(int x, int y){

	int tmp;
	while(y){
		tmp = x % y;
		x 	= y;
		y 	= tmp;
	}

	return x;

}