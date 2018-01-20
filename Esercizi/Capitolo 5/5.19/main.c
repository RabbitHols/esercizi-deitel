/*
Scrivete una funzione che visualizzi al margine sinistro dellos chermo un quadrato di 
asterischi il cui lato sia stato specificato nel parametro side.
*/

#include <stdio.h>
#include <stdlib.h>
	
void side(int lato);

int main(int argc, char const *argv[])
{
	
	side(atoi(argv[1]));

	return 0;
}

void side(int lato){

	printf("\n");

	for(int cnt_1 = 0; cnt_1 < lato; cnt_1++){
		for(int cnt_2 = 0; cnt_2 < lato; cnt_2++){
			printf("*\t");
		}
		printf("\n");
	}
	printf("\n");

}