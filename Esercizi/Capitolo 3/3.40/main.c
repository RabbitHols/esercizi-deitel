/**
Visualizzare una scacchiera con asterischi tipo cosi

	* * * *
	 * * * *
	* * * *
	 * * * *
**/

#include <stdio.h>

int main(){


	int row;
	int column;

	for(row = 0x0; row < 8; row++){
		for(column = 0x0; column < 8; column++){
			printf("* ");
		}
		printf("\n");
		(row % 2 != 0) ?: printf(" ");
	}

	return 0;
}