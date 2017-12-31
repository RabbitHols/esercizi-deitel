#include <stdio.h>

int main(){

	int x = 6;
	int y = 4;

//	!(x < 5) && !(y >= 7) equivale a (x > 5) && (y <= 7)

	(!(x < 5) && !(y >= 7)) ? printf("ok") : printf("non ok");
	printf("\n");
	((x > 5) && (y <= 7)) ? printf("ok") : printf("non ok");
	printf("\n");

// 	!( a == b) || !(g != 5) equivale a (a != b) || (g == 5)

	int a = 3;
	int b = 3;
	int g = 5;

	(!( a == b) || !(g != 5)) ? printf("ok") : printf("non ok");
	printf("\n");
	( (a != b) || (g == 5)) ? printf("ok") : printf("non ok");


	return 0;
}