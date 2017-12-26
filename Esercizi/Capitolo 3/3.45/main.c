/**
 * Scrivere un programma che prenda in input tre dati ti tipo int e indica se possono 
 * essere i lati di un triangolo 
 **/


#include <stdio.h>
#include <stdlib.h>

#define TRIANGOLO_EQUILATERO(a,b,c) ( !((a)^(b) | (b)^(c)) )
#define TRIANGOLO_ISOSCELE(a,b,c) (a == b && b != c || a == c && c != b || b == c && a != b )	 
#define TRIANGOLO_SCALENO(a,b,c) (a != b && b != c && c != a)

int main(int argc,char const *argv[]){
	
	int a;
	int b;
	int c;

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);

	if(TRIANGOLO_EQUILATERO(a,b,c))	{printf("E' un triangolo equilatero\n");}
	if(TRIANGOLO_ISOSCELE(a,b,c))	{printf("E' un triangolo isoscele\n");	}	
	if(TRIANGOLO_SCALENO(a,b,c))	{printf("E' un triangolo scaleno\n");	} 
  

	return 0;
}






