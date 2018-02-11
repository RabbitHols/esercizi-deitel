/*
Sempre esercizio tipo moltiplicazioni solo che:
	a) Modificate il programma in modo da consentire
	all'utente  di immettere un livello di difficoltà
	1 sta per operazioni ad una cifra
	2 sta per operazioni a due cifre

	b)Poi modificare anche per fargli scegliere il tipo di operazioni
	1 sta per +
	2 sta per -
	3 sta per *
	4 sta oer /
	5 sta per tutte scelte a caso

	*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

void regolamento(int art);
void flush(char);


float genex(int num);
float quickMath(int, const float, const float);

char simbolo(int num);

void checkinput(int *);

int main(int argc, char const *argv[])
{	
	srand(time(NULL));

	int numero_domande 		= 0;
	int risposteGiuste 		= 0;
	int risposteSbagliate 	= 0;
	float perc_corrette 	= 0;
	float perc_sbagliate 	= 0;
	
	int LvDfc 	= 1; // Livello di difficoltà
	int TpOpr 	= 1; // Tipo di operazioni
	int loopLv 	= 1; // Loop richiesta livello difficoltà

	float num_1;
	float num_2;
	float risultato;

	do{
		system("clear"); // Funzione su linux, ma su windows il comando è cls
		regolamento(0);
		scanf("%d", &TpOpr);

		switch(TpOpr){
			case 1: // Operazione addizione
				do{
					regolamento(1);
					scanf("%d", &LvDfc);
					flush(LvDfc);
						switch(LvDfc){ // Scelta lvl difficoltà
							case 1: 
							num_1 = genex(1);
							num_2 = genex(1);
							break;

							case 2: 
								num_1 = genex(2);
								num_2 = genex(2);
							break;

							default: regolamento(2);
						} // Fine switch LvDfc

					regolamento(4); // Chiede quanto fa senza specifica il tipo di operazione
					printf("%.2f %c %.2f :", num_1, simbolo(TpOpr), num_2);
					scanf("%f", &risultato);
					flush(risultato);
					if(risultato == quickMath(TpOpr, num_1, num_2)){
						risposteGiuste++;
						regolamento(5);
					} else {
						risposteSbagliate++;
						regolamento(6);
					}	
					numero_domande++;
					checkinput(&loopLv);

					system("clear"); // Funzione su linux, ma su windows il comando è cls

				} while(loopLv); // Fine do/while LvDfc
			break;

			case 2: // Operazione sottrazione
				do{
					regolamento(1);
					scanf("%d", &LvDfc);
					flush(LvDfc);
						switch(LvDfc){ // Scelta lvl difficoltà
							case 1: 
							num_1 = genex(1);
							num_2 = genex(1);
							break;

							case 2: 
								num_1 = genex(2);
								num_2 = genex(2);
							break;

							default: regolamento(2);
						} // Fine switch LvDfc

					regolamento(4); // Chiede quanto fa senza specifica il tipo di operazione
					printf("%.2f %c %.2f :", num_1, simbolo(TpOpr), num_2);
					scanf("%f", &risultato);
					flush(risultato);
					if(risultato == quickMath(TpOpr, num_1, num_2)){
						risposteGiuste++;
						regolamento(5);
					} else {
						risposteSbagliate++;
						regolamento(6);
					}	
					numero_domande++;
					checkinput(&loopLv);

					system("clear"); // Funzione su linux, ma su windows il comando è cls

				} while(loopLv); // Fine do/while LvDfc
			break;


			case 3: // Operazione moltiplicazione
				do{
					regolamento(1);
					scanf("%d", &LvDfc);
					flush(LvDfc);
						switch(LvDfc){ // Scelta lvl difficoltà
							case 1: 
							num_1 = genex(1);
							num_2 = genex(1);
							break;

							case 2: 
								num_1 = genex(2);
								num_2 = genex(2);
							break;

							default: regolamento(2);
						} // Fine switch LvDfc

					regolamento(4); // Chiede quanto fa senza specifica il tipo di operazione
					printf("%.2f %c %.2f :", num_1, simbolo(TpOpr), num_2);
					scanf("%f", &risultato);
					flush(risultato);
					if(risultato == quickMath(TpOpr, num_1, num_2)){
						risposteGiuste++;
						regolamento(5);
					} else {
						risposteSbagliate++;
						regolamento(6);
					}	
					numero_domande++;
					checkinput(&loopLv);

					system("clear"); // Funzione su linux, ma su windows il comando è cls

				} while(loopLv); // Fine do/while LvDfc
			break;

			case 4: // Operazione addizione
				do{
					regolamento(1);
					scanf("%d", &LvDfc);
					flush(LvDfc);
						switch(LvDfc){ // Scelta lvl difficoltà
							case 1: 
							num_1 = genex(1);
							num_2 = genex(1);
							break;

							case 2: 
								num_1 = genex(2);
								num_2 = genex(2);
							break;

							default: regolamento(2);
						} // Fine switch LvDfc

					regolamento(4); // Chiede quanto fa senza specifica il tipo di operazione
					printf("%.2f %c %.2f :", num_1, simbolo(TpOpr), num_2);
					scanf("%f", &risultato);
					flush(risultato);
					if(risultato == quickMath(TpOpr, num_1, num_2)){
						risposteGiuste++;
						regolamento(5);
					} else {
						risposteSbagliate++;
						regolamento(6);
					}
					numero_domande++;
					checkinput(&loopLv);

					system("clear"); // Funzione su linux, ma su windows il comando è cls

				} while(loopLv); // Fine do/while LvDfc
			break;


			case 5: // Operazioni multiple
				do{
					TpOpr = 1 + rand() % 4;

					regolamento(1);
					scanf("%d", &LvDfc);
					flush(LvDfc);
						switch(LvDfc){ // Scelta lvl difficoltà
							case 1: 
							num_1 = genex(1);
							num_2 = genex(1);
							break;

							case 2: 
								num_1 = genex(2);
								num_2 = genex(2);
							break;

							default: regolamento(2);
						} // Fine switch LvDfc

					regolamento(4); // Chiede quanto fa senza specifica il tipo di operazione
					printf("%.2f %c %.2f :", num_1, simbolo(TpOpr), num_2);
					scanf("%f", &risultato);
					flush(risultato);
					if(risultato == quickMath(TpOpr, num_1, num_2)){
						risposteGiuste++;
						regolamento(5);
					} else {
						risposteSbagliate++;
						regolamento(6);
					}
					numero_domande++;
					checkinput(&loopLv);

					system("clear"); // Funzione su linux, ma su windows il comando è cls

				} while(loopLv); // Fine do/while LvDfc
			break;


			default: regolamento(2); break;
		}

	checkinput(&TpOpr);	

	}while(TpOpr);

	perc_corrette 	= (float)(risposteGiuste * 100) / numero_domande;
	perc_sbagliate 	= (float)(risposteSbagliate * 100) / numero_domande;

	printf("Numero domande fatte: %d\n", numero_domande);
	printf("Numero risposte corrette %d\n", risposteGiuste );
	printf("Numero risposte sbagliate %d\n", risposteSbagliate );

	puts("\n\n");

	printf("Percentuale risposte corrette: %.2f\n", perc_corrette);
	for(int cnt = 0; cnt < (int)(perc_corrette / 10); cnt++){
		printf("+");
	}

	puts("\n\n");
	printf("Percentuale risposte sbagliate: %.2f\n", perc_sbagliate);
		for(int cnt = 0; cnt < (int)(perc_sbagliate / 10); cnt++){
		printf("-");
	}

	puts("\n\n");
	return 0;
}

void checkinput(int *check){

	char qst;

	do{
		regolamento(3);
		scanf("%c", &qst);
		flush(qst);
		system("clear");
	}while(qst != 'y' && qst != 'n');

	if(qst == 'y'){
		*check = 1;
	}
	if(qst == 'n'){
		*check = 0;
	}


}

float quickMath(const int tipo_operazione, const float num_1, const float num_2){
	switch(tipo_operazione){
		case 1: 
			return num_1 + num_2;
		break;

		case 2:
			return num_1 - num_2;
		break;

		case 3:
			return num_1 * num_2;
		break;

		case 4:
			return num_1 / num_2;
		break;
	}

	return 0;
}
	


float genex(int num){
				int a;
				switch(num){
					case 1:
					a = rand() %  10;
					break;
					case 2:
					a = rand() % 100;
					break;
				}

				return a;
}

void regolamento(int art){

				int rnd;

				switch(art){
					case 0:
					puts("\nScegli il tipo di operazioni da svolgere:\n");
					puts("\n1 per le addizioni\n");
					puts("\n2 per le sottrazioni\n");
					puts("\n3 per le moltiplicazioni\n");
					puts("\n4 per le divisioni\n");
					puts("\n5 per tutte quante\n");
					puts("\n");
					break;

					case 1: 
					puts("\nScelgi il tipo di difficoltà:\n");
					puts("\n1 per operazioni con una cifra\n");
					puts("\n2 per operazioni con due cifre\n");
					puts("\n");
					break;

					case 2:
					puts("\nOperazione non consentita\n");
					break;

					case 3:
					printf("\nContinuare ? y/n ");
					break;

					case 4:
					printf("\nQuanto fa: ");
					break;

					case 5:
						rnd = rand() % 4;
						switch(rnd){
							case 0: puts("Complimenti, la risposta è corretta\n"); break;
							case 1: puts("Bravo !\n"); break;
							case 2: puts("Fantastico! continua cosi !\n"); break;
							case 3: puts("Bravissimo !\n"); break;
						}
					break;

					case 6:
						rnd = rand() % 4;
						switch(rnd){
							case 0: puts("Dai su riprovaci non ti arrendere\n"); break;
							case 1: puts("Sbagliato, forse devi ripassare\n"); break;
							case 2: puts("E no! non ci siamo. . .\n");
							case 3: puts("Asino !\n"); break;
						}
					break;

					
				}
}

char simbolo(int num){

	switch(num){
		case 1:
			return '+';
		break;

		case 2:
			return '-';
		break;

		case 3:
			return '*';
		break;

		case 4:
			return '/';
		break;
	}

	return 0;
}

void flush(char c){
	while(c != '\n' && getchar() != '\n');
}



