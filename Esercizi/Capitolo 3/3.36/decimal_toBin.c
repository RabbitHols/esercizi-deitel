#include <stdio.h>

int main(){


	int decimale = 12;
	int n, resto;

	while(decimale != 0){
		n = decimale % 2;
		decimale /= 2;
		printf("%d", n);
	}

	printf("\n");

	return 0;
}
