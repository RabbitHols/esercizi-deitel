/** 
disegna un scacchiera con *
**/

#include <stdio.h>

void disegna_Scacchiera(){
	for (int i = 0; i < 8; ++i)
	{
		if(i % 2 == 0){
			for (int i = 0; i < 8; ++i){
			printf("*");
			}
		}
		else{
			printf(" ");
			for (int i = 0; i < 8; ++i){
			printf("*");
			}
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	disegna_Scacchiera();

	return 0;
}