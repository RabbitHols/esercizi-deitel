/*
Crea quadrato specifica dimensione e carattere da stampere
*/

#include <stdio.h>
#include <stdlib.h>

void quadrato(int, char);

int main(int argc, char const *argv[])
{
	
	int side 			=	atoi(argv[1]);	
	char fillCharacter 	=	argv[2][0];


	quadrato(side, fillCharacter);

	return 0;
}

void quadrato(int side, char fillCharacter){
	for(int cnt_1 = 0; cnt_1 < side; cnt_1++){
		for(int cnt_2 = 0; cnt_2 < side; cnt_2++){
			printf("%c", fillCharacter);
		}
		printf("\n");
	}
}