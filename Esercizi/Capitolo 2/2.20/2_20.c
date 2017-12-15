/**

Scrivere un programma che legga il raggio di un cerchio e visualizzi il diametro, la circonferenza e l'area dello stesso,
Usate il valore costante 3.14159 per "PiGreco".Eseguite ognuno di questi calcoli all'interno della istruzione printf e usate 
la specifica di conversione "%f"

**/

#include <stdio.h>

void area(int raggio){
	double PIGRECO = 3.14;
	printf("AREA = %.2f\n", PIGRECO * (raggio * raggio));
}

void circonferenza(int raggio){
	double PIGRECO = 3.14;
	printf("CIRCONFERENZA = %.2f\n", PIGRECO * (raggio * 2));	
}

void diametro(int raggio){
	double PIGRECO = 3.14;
	printf("DIAMETRO = %.2f\n", (double)raggio * 2);	
}

int main(int argc, char const *argv[])
{
	
	int raggio = 12;

	diametro(raggio);
	circonferenza(raggio);
	diametro(raggio);
	return 0;
}