/**

Implementare una funzione pow 

**/

#include <stdio.h>

int integer_Pow(int,int);

int main(int argc, char const *argv[])
{

printf("%d\n", integer_Pow(2,3));

	return 0;
}

int integer_Pow(int base,int esponente){

	if(base == 0 && esponente == 0){
		return 1;
	}else if(esponente == 0){
		return 0;
	} 

	int risultato = base;

	int cnt;

	for(cnt = 1; cnt < esponente; cnt++){
		risultato = risultato * base;
	}

	return risultato;
}
