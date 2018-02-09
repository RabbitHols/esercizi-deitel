/*
Scrivete un programma chiamato indovina numero: il vostro programma
sceglierà il numero da individuare, selezionando un intero a caso compreso
nell'intervallo da 1 a 1000. 

Il programma quindi visualizzerà:

I have a number between 1 and 1000
Can you guess my number
Please type your first guess


Il giocatore allora digiterà una prima ipotesi. Il programma risponderà con una
delle seguenti frasi:

1) Complimenti hai indovinato
2) Troppo piccolo ritenta
3) Troppo grande ritenta

Loop finquando non indovina

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{	
	
	int num = num = 1 + rand() % 1001;
	int check;

	
	do{
		puts("Prova a indovinare il numero\n");
		scanf("%d", &check);

		if(check < num){ puts("Troppo piccolo ritenta");} 
		if(check > num){ puts("Troppo grande ritenta");}
		if(check == num){puts("Complimenti hai vinto");}
	} while(check != num);

	return 0;
}