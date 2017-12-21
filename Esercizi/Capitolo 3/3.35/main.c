/*
Prendere un numero di 5 cifre e si decida se esso è palindromo 
*/

/*
 * Un modo per risolvere l'esercizio è creare un numero inverso tramite gli operatori / e % 
 * e vedere se sono uguali
 */

#include <stdio.h>
int main()
{
	int numero;
	int palindromo;
	int revPlindromo;
	int store;

	printf("### DAMMI UN NUMERO ###\n");
	scanf("%d", &numero);

	palindromo = numero;	
	revPlindromo = 0;

	while(numero != 0){
		store = numero % 10;
		revPlindromo = (revPlindromo * 10) + store;
		//printf("Store :%d\n", store);
		//intf("RevPal:%d\n", revPlindromo);
		numero = numero / 10;
	}	
  	
	if(palindromo == revPlindromo){printf("PALINDROMO\n");}
	else { printf("NON PALINDROMO\n"); };


    return 0;
}
