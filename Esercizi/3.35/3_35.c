
/**

Verificare se un numero è palindromo scomponendolo e inserendolo in un array;

1) Prendere argomento da argv *Tipo char
2) Controllare la lunghezza di argv
3) Inserire il tutto in un array di char
4) Trasformare il tutto in un array di int
5) Trasformare l array di int in un solo int
6) Scomporre l intero
7) Inserirlo in un array
8) Controllare se è palindromo


**/


#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[]){

if(argc !=2){
	printf("DEVI PASSARE ALMENO UN ARGOMENTO\n");
	printf("NUMERO ARGOMENTI PASSATI: %d\n", argc - 1);
return 0;

}


int buff = strlen(argv[1]);
char n[buff + 1];

strcpy(n, argv[1]);

int t[sizeof(n) - 1];
int base = 1;
int conv = 0;
int numero_Finale = 0x0; 

for(int i = sizeof(n) - 2, cont = 0; i >= 0; i--, cont++){
	
	conv = n[i] - '0';
	t[cont] = conv * base;
	base *= 10;
	
}

for(int i = 0; i < sizeof(t) / 4; i++){
	
	numero_Finale += t[i];

}


float numero = (float) numero_Finale;
int sentinella = 0x0;
base = 1; // Parto dal presupposto che sia di 32bit, la riuso
int unit;
int cont = 1;

// Ricaviamo la base
	sentinella = (int) numero;
while(numero > 9){
	
	numero = numero / 10;
	base = base * 10;
	cont++;
} 



// Scomponiamo

int arr[cont];

for(int i = 0; i < cont; i++){
	unit = sentinella / base;
	arr[i] = unit;
	sentinella = sentinella % base;
	base /= 10;
}


// Controlliamo se il numero è palindromo


	for(int i = 0, min = 1; i < cont / 2; i++, min++){
	if(arr[i] == arr[cont - min]){	
		} else { printf("NON E' PALINDROMO\n"); return 0; };
	}
 

printf("E' palindromo\n");


return 0;
}


