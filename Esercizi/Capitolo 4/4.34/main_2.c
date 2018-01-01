#include <stdio.h>
#include <stdlib.h>

void toBin(int);
void toOct(int);
void toHex(int);

int main(){


	printf("DECIM\t\tBINARIO\t\tOTTALE\t\tESADECIMALE\n");

	for(int cnt = 1; cnt <= 20; cnt++ ){
		printf("%d\t\t", cnt);
		toBin(cnt);
		printf("\t\t");
		toOct(cnt);
		printf("\t\t");
		toHex(cnt);
		printf("\n");
	}


	return 0;
}

void toBin(int num){
	int numBin;
	int resto;
	int cnt = 1;

	numBin = 0;
	while(num != 0){
		resto = num % 2;
		numBin = (resto * cnt) + numBin; 
		num = num / 2;
		cnt = cnt * 10;
	}

	printf("%d", numBin);
}

void toOct(int num){
	int numOct;
	int resto;
	int cnt = 1;

	numOct = 0;

	while(num != 0){
		resto = num % 8;
		numOct = (resto * cnt) + numOct;
		num = num / 8;
		cnt = cnt * 10;
	}

	printf("%d", numOct);
}

void toHex(int num){
	char *numHex;
	int resto;
	int cnt = 0;

	int sentinella = num;

	numHex = (char *)calloc(cnt, sizeof(int));

	while(num != 0){
		numHex = realloc(numHex, (cnt + 1) * sizeof(int));
		resto = num % 16;
		if(resto < 10){
			resto = resto + 48;
		} else {
			resto =  resto + 55;
		}

		numHex[cnt] = resto;
		cnt++;

		num = num / 16;
	}


	for(int cont = cnt - 1; cont >= 0; cont--){
		printf("%c", numHex[cont]);
	}

	free(numHex);

}