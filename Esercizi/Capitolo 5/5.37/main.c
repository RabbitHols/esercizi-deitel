/*

Scrivere una funzione ricorsiva power(base,exponent) che quando invocata restituisca base^exponent

*/

#include <stdio.h>

int pot(int, int);

int main(int argc, char const *argv[])
{
	
	printf("%d\n", pot(3,0));

	return 0;
}

int pot(int base, int exponent){

	if(exponent == 0){
		return 1;
	}
	return (exponent != 1)? base * pot(base,exponent - 1) : base;

}