/**

Sviluppare un programma che determini la paga lorda per ognuno dei diversi impiegati.
L'azienda, per le prime 40 ore lavorate da ogni impiegato, paga il "salaro orario di base",
mentre per tutte le ore lavorate in aggiunta alle 40, elargisce "una volta e mezza il salario di base". 
Vi sono stati forniti: una lista degli impiegati dell'azienda, il numero di ore lavorate da ogni impiegato
nell'ultima settimana e il salario orario di ogni impiegato.
Il vostro programma dovrà prendere in input, per ogni impiegato, le sudette informazioni e dovrà quindi determinare e visualizzare la paga lorda di ognuno di
loro.


DI seguito è ripratto un esempio dell'iterazione per quanto riguardo i/o dei dati:

	Enter # of hours worked (-1 to end): 39
	Enter hourly rate of the worker ($00.00): 10.00
	Salary is $390.00

	Enter # of hours worked (-1 to end): 40
	Enter hourly rate of the worker ($00.00): 10.00
	Salary is $400.00

	**/

#include <stdio.h>

float emissioneSalario(float oreLavorate, float pagaOraria);

int main(){

	float oreLavorate;
	float pagaOraria;
	float salarioFinale;

	int sentinella;

	while(sentinella != 1){

		printf("Enter # of hours worket (-1 to end): ");
		scanf("%f", &oreLavorate);

		printf("\nEnter hourly rate of the worket ($00.00): ");
		scanf("%f", &pagaOraria);

		salarioFinale = emissioneSalario(oreLavorate, pagaOraria);

		printf("\n Salary is %f\n", salarioFinale);

	}


	return 0;
}

float emissioneSalario(float oreLavorate, float pagaOraria){

	float stipendioStd;
	float stipendioStr;
	float stipendioFnl;
	float pagaStd;

	int contatore = 1;

	stipendioStd = 0;
	stipendioStr = 0;
	stipendioFnl = 0;

	pagaStd = pagaOraria + (pagaOraria / 2);

	contatore = 0;

	for(contatore; contatore <= oreLavorate; contatore++){
		if(contatore < 40){stipendioStd = stipendioStd + pagaOraria;}
		if(contatore > 40){stipendioStr = stipendioStr + pagaStd;}
	}

	return stipendioFnl = stipendioStd + stipendioStr;

}



/*
float emissioneSalario(float oreLavorate, float pagaOraria){

	float calcoloOreStraordinari;
	float salarioFinale;
	float pagaStandard;
	float oreStraordinarie;

	pagaStraordinari = (pagaOraria / 2) + pagaOraria;

 	if(oreLavorate > 40){
 		oreStraordinarie = oreLavorate - 40;
 		calcoloOreStraordinari = oreStraordinarie * pagaStraordinari;
 	}

	salarioFinale = pagaStandard + calcoloOreStraordinari;
	return salarioFinale;
}*/
