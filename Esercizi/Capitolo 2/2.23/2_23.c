/** 

scrivete 5 interi e determinate il maggiore e minore

**/

#include <stdio.h>

void maggiore(int a, int b, int c, int d, int e){
	int maggiore = a;

	maggiore = (maggiore > b) ? maggiore : b;
	maggiore = (maggiore > c) ? maggiore : c;
	maggiore = (maggiore > d) ? maggiore : d;
	maggiore = (maggiore > c) ? maggiore : c;
	maggiore = (maggiore > e) ? maggiore : e;

	printf("MAGGIORE = %d\n", maggiore);
}

void minore(int a, int b, int c, int d, int e){
	int minore = a;

	minore = (minore < b) ? minore : b;
	minore = (minore < c) ? minore : c;
	minore = (minore < d) ? minore : d;
	minore = (minore < c) ? minore : c;
	minore = (minore < e) ? minore : e;

	printf("MINORE = %d\n", minore);
}

int main(int argc, char const *argv[])
{
	
	int a = 12; int b = 13; int c = 1; int d = 21; int e = 33;

	maggiore(a,b,c,d,e);
	minore(a,b,c,d,e);


	return 0;
}