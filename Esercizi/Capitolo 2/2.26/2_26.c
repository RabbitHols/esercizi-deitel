/**

immettere due interi e verificare che l'uno sia multiplo dell'altro

**/

#include <stdio.h>

void verifico_M(int a, int b){
	int multiplo = (a % b == 0) ? printf("E' multiplo") : printf("Non è multiplo");
}

int main(int argc, char const *argv[])
{
	verifico_M(4,2);
	return 0;
}