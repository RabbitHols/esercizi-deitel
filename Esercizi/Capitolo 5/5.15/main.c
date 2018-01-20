/**	

Definite una funzione hypotenuse che calcoli la lunghezza dell'ipotenusa di un triangolo
rettangolo quando siano dat gli altri due lati. Utilizzate questa funzione in un
programma che determini la lunghezza dell'ipotenusa per ognuno dei seguenit triangolo. 
La funzione dobrà dicere due argomenti di tipo double e resituire l'ipotenusa come un 
double.
Testate il programma con questi dati

TRIANGOLO:	LATO 1: 	LATO 2:

1			3,0			4,0
2			5,0			12,0	
3			8,0			15,00

**/

#include <stdio.h>
#include <math.h>

double hypotenuse(double, double);

int main(){

	double lato_1, lato_2;

//	Triangolo nr. 1

	lato_1 = 3.0;	lato_2 = 4.0;

	printf("%f\n", hypotenuse(lato_1, lato_2));

// Triangolo nr. 2

	lato_1 = 5.0; lato_2 = 12.0;

	printf("%f\n", hypotenuse(lato_1, lato_2));

// Triangolo nr. 3

	lato_1 = 8.0; lato_2 = 15.00;

	printf("%f\n", hypotenuse(lato_1, lato_2));

	return 0;
}

double hypotenuse(double lato_1, double lato_2){
	return pow(lato_1,2) + pow(lato_2,2);
}
