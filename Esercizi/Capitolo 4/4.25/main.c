/**
Visualizzare una tabella di quivalenza tra
decimali, binari, ottali ed esadecimali.
**/

#include <stdio.h>

int ToBin(int);
int ToOctal(int);
void ToHex(int);

int main(){

	int cnt;

	printf("DECIMALE | BINARIO | OTTALE | ESADECIMALE |\n");

	for(cnt = 0; cnt <= 10; cnt++){
			printf("%d\t   %d\t\t%d\t  ", cnt, ToBin(cnt), ToOctal(cnt));
			ToHex(cnt);
			printf("\n");
	}

	return 0;
}

int ToBin(int num){
	int resto 	= 0;
	int numBin	= 0;
	int cnt 	= 1;
	while(num != 0){
		resto = num % 2;
		numBin = (resto * cnt) + numBin;
		num = num / 2;
		cnt = cnt * 10;
	}
	return numBin;
}

int ToOctal(int num){
	int resto 	= 0;
	int numOct 	= 0;
	int cnt = 1;
	while(num != 0){
		resto = num % 8;
		numOct = (resto * cnt) + numOct;
		num = num / 8;
		cnt = cnt * 10;
	}

	return numOct;
}

void ToHex(int num){
	int resto = 0;
	char numHex[100];
	int cnt = 0;

	while(num != 0){
		resto = num % 16;
		if(resto < 10){
			numHex[cnt] = resto + 48; 
		} else {
			numHex[cnt] = resto + 55;
		}
		num = num / 16;
		++cnt;
	}

	for(int cont = 0; cont < cnt; cont++){
		printf("%c", numHex[cont]);
	}

}
