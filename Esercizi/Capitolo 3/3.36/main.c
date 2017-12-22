/**
 * Trasformare un numero da binario a decimale
 */

#include <stdio.h>
#include <math.h>

int main(){

	int BinaryNum;
	int DecimalNum;
	int resto;
	int cont;

	cont 		= 0;
	DecimalNum 	= 0;

	printf("### Dammi un numero \n N.D binario dal più grande al più piccolo\n");
	scanf("%d", &BinaryNum);

	while(BinaryNum != 0){
		resto = BinaryNum % 10;
		DecimalNum = DecimalNum + (resto * pow(2,cont) );
		BinaryNum = BinaryNum / 10;
		cont++;
	}

	printf("%d\n", DecimalNum);

	return 0;
}
