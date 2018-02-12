/*

Scrivete un programma che simuli il lancio di due dadi. Il programma dovrà
utilizzare rand per lanciare il primo dado e invocarla nuovamente per lanciare
il secondo dado. Dovrà quindi essere calcolata la somma dei due valori.

# NOTA: Poichè ogni dado può mostrare un valore intero compreso tra 1 e 6, 
la somma dei due valori potrà variare tra 2 e 12, con 7 somma più frequente e 2 e 12
come somme meno frequenti

Il vostro programma dovrà lanciare i due dadi 36mila volte. Utilizzare un 
vettore unidimensionale per sommare il numero di occorrenze di ogni somma
possibile. Visualizzate i risultati in un formato tabulare. Determinare anche se
i totali sono sensati: Ci sono sei modi per ottenere un 7, perciò circa un
seso dei lanci dovrebbe ottenerlo

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANCI 36000

int main(int argc, char const *argv[]){
	

	int tot[11] = {0};

	int dado_1;
	int dado_2;
	int risultato;

	for(int cnt = 0; cnt < NUM_LANCI; cnt++){
		dado_1 = 1 + rand() % 6;
		dado_2 = 1 + rand() % 6;
		risultato = dado_1 + dado_2;

		++tot[risultato - 2];

	}	

	for(int cnt = 0; cnt < 11; cnt++){

		printf("| %d |", tot[cnt]);
	}

	return 0;
}