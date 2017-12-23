/**
Niente era solo un loop infinito con 2^cont;
*/


#include <stdio.h>

int main(int argc, char const *argv[])
{

	int var = 1;

	for(int i = 0; i < 32; i++){

		var = var * 2;
		printf("%d\n", var);

	}

	return 0;
}