/**
Scrivere un programma che esegua il fattoriale di 5
**/

#include <stdio.h>

int main(){

	int num = 5;
	int cnt = num - 1;

	while(cnt != 1){
		num = num * cnt;
		cnt--;
	}

	printf("%d\n", num);

	return 0;
}