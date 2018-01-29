/*
Scrivete una funzione che accetti in input l'ora, suddivisa in tre argomenti interi
(per le ore, i minuti e i secondi) e restituisca il numero dei secondi trascorsi 
dall'ultima volta che l'orologio a rintoccato le 12. Utilizzate questa funzione per 
calcolare la quantità di tempo in secondi che intercorre tra i due orari, entrambi 
i quali siano compresi all'interno di un ciclo di 12 ore dell'orologio.
*/

#include <stdio.h>
#include <stdlib.h>
	
int diff_tempo(int ore, int minuti, int secondi);

int main(int argc, char const *argv[])
{
	int ore 	= atoi(argv[1]);
	int minuti 	= atoi(argv[2]);
	int secondi = atoi(argv[3]);

	int tot_Tempo = diff_tempo(ore,minuti,secondi);

	printf("La differenza di tempo è di: %d secondi", tot_Tempo);

	return 0;
}

int diff_tempo(int ore, int minuti, int secondi){

	int ora_relativa = 12;
	int ora_Finale = ore - ora_relativa; // 4

	int oraToMin = ora_Finale * 60; 
	int minToSec = (minuti + oraToMin) * 60;
	int totSec = minToSec + secondi;

	return totSec;

}