/**
Decidere tramite parametro la grandezza del Rombo
**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	if(argv[1] == NULL){
		printf("Devi dare almeno un elemento come parametro\n");

		return 0;
	} 

	if(atoi(argv[1]) % 2 == 0){
		printf("Il programma accetta solo parametri dispari\n");

		return 0;
	}


	int cnt;
	int xcnt;
	int max = atoi(argv[1]);
	int scnt = max;
	int asterischi = 1;

	max = (max / 2) + 1;
	
	
	for(cnt = 1; cnt < max ;cnt++){
		for(scnt = max - cnt; scnt > 0; scnt--){
				printf(" ");
			}
		for(xcnt = 0; xcnt < asterischi; xcnt++){
			printf("*");
		}
		asterischi = asterischi + 2;
		printf("\n");

	}

	for(cnt = max; cnt > 0; cnt--){
		for(scnt = 0 + cnt; scnt < max; scnt++){
			printf(" ");
		}
		for(scnt = asterischi; scnt > 0; scnt--){
			printf("*");
		}
		printf("\n");
		asterischi = asterischi - 2;


	}

	
	return 0;
}