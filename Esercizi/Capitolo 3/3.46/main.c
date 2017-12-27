/**
Un azienda vuole trasmettere dei dati sulla linea telefonica, ma i suoi 
responsabili sono preoccupati del fatto che i propri telefoni potrebbero
essere spiati. TUtti i loro dati sono trasmessi come interi di 4 cifre.
Vi hanno chiesto quindi di scrivere un programma che crittografi i loro
dati in modo che possano essere trasmessi con maggior sicurezza. Il vostro 
programma dovrà leggere un intero di 4 cifre e crittografarlo nel modo 
seguente: sostituire ogni cifra con il resto ottenuto dalla divisione
di (la somma di quella cifra più 7) per 10. In seguito, scmabiare la prima cifra con la terza, e scambiare la seconda cifra con la quarta. Visualizzate
quindi l'intero crittografato. Scrivere un programma che prenda un intero di 4 cifre lo decifri, in modo da formare il numero originale.
**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int numero = atoi(argv[1]);
	int numero_clone = numero;
	int resto;

	int unita;
	int decina;
	int centinaia;
	int migliaia;

//	### 	SUPPONIAMO CHE IL NUMERO SIA 2843	###

// 		MI RICAVO L'UNITA'
		resto = numero_clone % 10;
		unita = resto;
		numero_clone = numero_clone / 10; 

//		MI RICAVO LA DECINA
		resto = numero_clone % 10;
		decina = resto;
		numero_clone = numero_clone / 10;

// 		MI RICAVO LA CENTINAIA
		resto = numero_clone % 10;
		centinaia = resto;
		numero_clone = numero_clone / 10;
		
//		MI RICAVO LA MIGLIAIA
		resto = numero_clone % 10;
		migliaia = resto;
		numero_clone = numero_clone / 10;

				
//	###	APPLICO LA FORMULA			###
		
		int numeroDaAddizionare 	=  7;
		int numeroDaMoltiplicare 	= 10;
		int risultatoOperazione;	

	
		risultatoOperazione = unita + 7;
		risultatoOperazione = risultatoOperazione * 10;
		risultatoOperazione = risultatoOperazione % unita;
		unita = risultatoOperazione;

		risultatoOperazione = decina + 7;
		risultatoOperazione = risultatoOperazione * 10;
		risultatoOperazione = risultatoOperazione % decina;
		decina = risultatoOperazione;
		
		risultatoOperazione = centinaia + 7;
		risultatoOperazione = risultatoOperazione * 10;
		risultatoOperazione = risultatoOperazione % centinaia;
		centinaia = risultatoOperazione;
	 	
		risultatoOperazione = migliaia + 7;
		risultatoOperazione = risultatoOperazione * 10;
		risultatoOperazione = risultatoOperazione % migliaia;
		migliaia = risultatoOperazione;
		
//	###	SCAMBIO POSIZIONI			###
	
		int temp;

		temp 		= migliaia;
		migliaia 	= decina;
		decina 		= temp;		

		temp 		= centinaia;
		centinaia 	= unita;
		unita 		= temp;

//	###	RICOMPONGO I NUMERI			###
		
		int num_lock	= 0;

		num_lock = (migliaia * 1000);
		num_lock = (centinaia * 100) + num_lock;
       		num_lock = (decina * 10) + num_lock;
		num_lock = unita + num_lock;

//	###	FINITO DI CRIPTOGRAFARE 		###
	

		printf("\t### IL NUMERO INSERITO PRECEDENETEMENTE ERA ###\n");
		printf("\t\t\t%d\n", numero);	
		printf("\n\n");
		printf("\t### IL NUMERO ORA E' DIVENTATO ###\n");
		printf("\t\t\t%d%d%d%d\n\n", migliaia,centinaia,decina,unita);


		

	return 0;
}



	



















