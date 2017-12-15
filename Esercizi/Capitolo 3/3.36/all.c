#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	
	int numeroDecimale = 12;

	printf("TRASFORMO IL DECIMALE IN BINARIO\n");
	
	printf("DECIMALE = %d\n", numeroDecimale);

	int resto = 0;
	int n = 0;

	printf("NUMERO BINARIO = ");

	while(numeroDecimale != 0){
	
	n = numeroDecimale % 2;
	numeroDecimale /= 2;
	printf("%d", n);

	}

	printf("\n");
	

	printf("TRASFORMO IL BINARIO IN DECIMALE\n");


	int numeroBinario = 1101;
	int a;
	int finale = 0;
	int cont = 0;

	printf("NUMERO BINARIO = %d\n", numeroBinario);

	while(numeroBinario != 0){

	a = numeroBinario % 2;
	numeroBinario /= 10;

	finale = finale + a * pow(2, cont);
	cont++;
	}

	printf("NUMERO DECINALE = %d\n", finale);

	return 0;
}
