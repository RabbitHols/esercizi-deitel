/*
Scrivere la funzione distance che calcoli la distanza tra due punti x1,y1 e x2,y2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int distanza(int x1, int y1, int x2, int y2){
	return pow(x1-x2,2) + pow(y1-y2,2);
}

int main(int argc, char const *argv[])
{
	
	int x1 = 5;
	int y1 = 10;

	int x2 = 3;
	int y2 = 4;

	int dist = distanza(x1,y1,x2,y2);

	printf("%d\n", dist);


	return 0;
}