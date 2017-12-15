/**

Una grande industria chimica retribuisce i propri venditori basandosi sulle provvigioni.
Il venditore riceve $200 la settimana più il 9% delle proprie vendite lorde portate a termine 
durante la settimana. Per esempio un venditore che in una settimana venda prodotti chimici per un valore di
$5000, riceverà $200 più il 9% di 5000, ovverosia un totale di $650. Scrivete un programma, che
prenda in input le vendite lorde di ogni venditore per l'ultima settimana e quindi calcoli e visualizzi 
il salario per ognuno di loro. Elaborate i conti di un venditore per volta. 
Ex:

Enter sales in dollars: 5000
Salary is: 650


**/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	float volumeVendita = 	0x0; 	
	float percentuale	=	0x0;
	float salario 		= 	0x0;


	volumeVendita		=  5000;
	percentuale 		= 	  9;
	salario 			= 	(volumeVendita * 9 / 100) + 200;

	printf("Salario %.2f\n", salario);





	return 0;
}