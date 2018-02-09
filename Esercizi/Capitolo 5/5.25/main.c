/*
 Scrivere una funzione che dia il minore tra 3 numeri in virgola mobile
*/

#include <stdio.h>

#define MIN(x,y)  ( (x < y)? x : y )   

int main(){

	float a;	a = 3.5;
	float b;	b = 2.5;
	float c;	c = 1.4;

	float min;	min = MIN(MIN(a,b),c);

	printf("%.2f\n", min);

	return 0;
}
