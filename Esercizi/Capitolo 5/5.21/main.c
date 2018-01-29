/**
Utilizzare le tecniche dell'esercizio 5.19 e 5.20 per produre un programma
che tracci un ampia gamma di forme.
**/

#include <stdio.h>
#include <stdlib.h>

void stampa_Quadrato(int, char);
void stampa_Rombo(int, char);


int main(int argc, char const *argv[])
{
	
	int 	lunghezza;
	char 	carattere;

	lunghezza =		atoi(argv[1]);
	carattere =		argv[2][0];

	stampa_Rombo(lunghezza, carattere);
	stampa_Quadrato(lunghezza, carattere);
	return 0;
}

void stampa_Quadrato(int lato, char lettera){
	for(int cnt_1 = 0; cnt_1 < lato; cnt_1++){
		for(int cnt_2 = 0; cnt_2 < lato; cnt_2++){
			printf("%c", lettera);
		}
		printf("\n");
	}
}

void stampa_Rombo(int lunghezza, char lettera){


	int cnt;
	int xcnt;
	int max = lunghezza;
	int scnt = max;
	int asterischi = 1;

	max = (max / 2) + 1;
	
	
	for(cnt = 1; cnt < max ;cnt++){
		for(scnt = max - cnt; scnt > 0; scnt--){
				printf(" ");
			}
		for(xcnt = 0; xcnt < asterischi; xcnt++){
			printf("%c", lettera);
		}
		asterischi = asterischi + 2;
		printf("\n");

	}

	for(cnt = max; cnt > 0; cnt--){
		for(scnt = 0 + cnt; scnt < max; scnt++){
			printf(" ");
		}
		for(scnt = asterischi; scnt > 0; scnt--){
			printf("%c", lettera);
		}
		printf("\n");
		asterischi = asterischi - 2;


	}
	
}