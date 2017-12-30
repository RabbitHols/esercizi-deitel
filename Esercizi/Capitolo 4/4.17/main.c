/**
Se un particolare cliente avesse un avuto un limite di credito di 2000€ 
ora sarebbe di 1000€. Dimezzare ogni tutti i limiti dei conti

Per ogni cliente vi saranno forniti i seguenti dati:
1) Numero conto del cliente
2) Il limite di credito del cliente prima delle recessione
3) Il saldo corrente del cliente (i soldi che il cliente deve)

**/

#include <stdio.h>

int main(){

	int check; 

	int N_Conto_Alberto = 10;
	int L_Conto_Alberto = 1000;
	int S_Conto_Alberto = 2000;

	int N_Conto_Mario 	= 11;
	int L_Conto_Mario 	= 3000;
	int S_Conto_Mario	= 1000;

	check = 0x0;

	while(check != -1){
		printf("\nDimmi il numero dei conto da controllare (-1) per uscire\n");
		scanf("%d", &check);

		if(check == 10){
			printf("Numero conto:\t\t\t%d\n", N_Conto_Alberto);
			printf("Limite conto precedente:\t%d\n", L_Conto_Alberto);
			printf("Limite conto attuale:\t\t%d\n", L_Conto_Alberto / 2);
			printf("Saldo conto attuale:\t\t%d\n", S_Conto_Alberto);
		}

		if(check == 11){
			printf("Numero conto:\t%d\n", N_Conto_Mario);
			printf("Limite conto precedente:\t%d\n", L_Conto_Mario);
			printf("Limite conto attuale:\t%d\n", L_Conto_Mario / 2);
			printf("Saldo conto attuale:\t%d\n", S_Conto_Mario);
		}


	}


	return 0;
}