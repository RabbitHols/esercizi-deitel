/**

Sviluppare un programma in C, che determini se il cliente di un grande magazzino abbia superato il limite 
di credito del suo conto. Per ogni cliente saranno disponibili i seguenti dati:

1)Il numero di conto 
2)Il saldo all'inizio del mese
3)Il totale di tutti gli articoli che il cliente ha messo in conto durante il mese corrente
4)Il totale di tutti i crediti applicati al conto di questo cliente durante il mese corrente.
5)Il limite di credito concesso

Il programma dovrà prendere in input tutti questi dati, calcolare il nuovo saldo ( = saldo iniziale + articoli messi in conto - crediti) e
determinare se il nuovo saldo superi il limite del credito del cliente. Per quei clienti che avranno superato il limite di credito, il
programma dovrà visualizzare il loro numero di conto.

Ex: 

Enter account nr: 100
Enter beginning balange: 5934.78
Enter totale charges: 1000
Enter totale credits: 500
Enter credit limit: 5500

Account:100
Credit limit: 5500
Balance: 5894.78
Credit Limit Exceeded	

**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

	int numeroConto = 100;
	float bilancio = 1000;
	float totaleArticoli = 123.45;
	float totaleCrediti = 321;
	float limiteCredito = 1500;

	float nuovoSaldo = bilancio + totaleArticoli - totaleCrediti;

	(nuovoSaldo < limiteCredito) ?: printf("\tLimite credito superato\t\n \tAccount: %d\n\tLimite Credito: %.2f\n\tBilancio: %.2f\n", numeroConto, limiteCredito, nuovoSaldo);
	return 0;
}