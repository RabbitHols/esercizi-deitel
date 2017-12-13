/**

Gli automobilisti sono interessati al numero di chilometri percorsi dalle proprie auto.
Un autista ha mantenuto traccia di diversi pieni di benzina, registrando i chilometri
percorsi e i litri utilizzati per ogni pieno. Sviluppare un programma che prenda in input i chilometri
percorsi e i litri utilizzati per ogni pieno. Il programma dovrà calcolare e visualizzare i
chilometri per litro ottenuti da ogni pieno. Dopo aver elavotrato tutte le informazioni in input, il 
programma dovrà calcolare e visualizzare anche i chilometri per litro ottenuti complessivamente da tutti i pieni.

Ex:
Enter the gallons used: 12.8
Enter the miles driver: 287
The miles / galos for this tank was 22.421875

**/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	double carburante = 0x0;	double kilometri = 0x0;
	double rapporto = 0x0;


		printf("\t Inserisci il carburante usato\n");
		scanf("%lf", &carburante);

		printf("\t Inserisci i km percorsi\n");
		scanf("%lf", &kilometri);

		rapporto = kilometri / carburante;

		printf("\t\n ##### DATI ELABORATI #### \n");
		printf("\t Carburante usato: \t%.2f\n", carburante);
		printf("\t Kilometri percorsi: \t%.2f\n", kilometri);
		printf("\t Rapporto: \t\t%.2f\n", rapporto);


	return 0;
}