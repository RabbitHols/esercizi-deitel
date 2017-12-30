/**
 * Scrivere un programma che calcoli e visualizzi la media di diversi numeri
 * supponiamo che per finire l'iterazione dobbiamo immettere il numero 9999
**/

#include <stdio.h>

int main(){

	int cnt = 0;
	int num = 0;
	int acc = 0;
	while(num != 9999){
		acc = acc + num;		
		printf("Dammi numero\n");
		scanf("%d", &num);
		cnt++;
	}
	--cnt;

	printf("%d\n", acc);
	printf("%d\n", cnt);
	printf("\n%d\n", acc / cnt);


	return 0;
}
