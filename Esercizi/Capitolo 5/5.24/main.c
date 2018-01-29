/*
 Da C° a F°
 	: F° = (9/5)°C+32
 Da F° a C°
 	: C° = (5/9)x(°F - 32)
*/

#include <stdio.h>

double toFar(double temp);
double toCel(double temp);

void tabella();

int main(){

	int gradi = 20.00;

	printf("%f\n", toFar(gradi));

	printf("%f\n", toCel(toFar(gradi)));

	return 0;
}

double toCel(double temp){
	
	return ( (5.0/9.0)* (temp - 32));

}

double toFar(double temp){

	return ( (temp * 9.0/5.0) + 32  );

}

void tabella(){

	char arr[]



}

