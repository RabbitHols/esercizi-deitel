/**

Scrivere un programma che legga il raggio di un cerchio (float)
e quindi calcoli e visualizzi il diametro, la circonferenza e l'area.
Utilizza 3.14159 come PiGreco.


**/

// Diametro 		= 2r
// Circonferenza 	= 2 PiGreco r
// Area 			= PiGreco r^2	
	
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	float Area;
	float Raggio;
	float PiGreco;
	float Diametro;
	float Circonferenza;

// Mi sono rotto di usare la scanf

	//printf("Dammi raggio del cerchio: \n");
	// scanf("%f", &Raggio);

// Mi faccio tutti i calcoli

	Raggio = atoi(argv[1]);
	PiGreco 		= 3.14159;
	Diametro 		= 2 * Raggio;
	Circonferenza 	= 2 * (PiGreco * Raggio);
	Area 			= PiGreco * (Raggio * Raggio);


	printf("Il diametro è di %f\n", Diametro);
	printf("La circonferenza è di %f\n", Circonferenza);
	printf("L'area è di %f\n", Area);

	return 0;
}