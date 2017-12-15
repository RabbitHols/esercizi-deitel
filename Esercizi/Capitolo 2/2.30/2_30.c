/**

Spezzare un numero di 5 cifre

**/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num = 213;
	int unita, decina, centinaia;

	centinaia = num / 100 ;
	decina = num / 10 - (num / 100 * 10);
	unita = num - (centinaia * 100) - (decina * 10);

	printf("%d ", centinaia);
	printf("%d ", decina);
	printf("%d\n", unita);
	return 0;
}