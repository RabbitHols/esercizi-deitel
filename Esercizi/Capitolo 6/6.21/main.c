/*
(Sistema di prenotazione delle linee aree)

Una piccola compagnia aerea ha appena comprato un computer per il suo nuovo sistema
di prenotazione automatica. Il presidente vi ha chiesto di programmare il nuovo
sistema. Voi dovete scrivere un programma che assegni i posti su un volo
dell'unico aereo dell'aereolinea (capacità: 10 posti)

Il vostro programma dovrà visualizzare il seguente menu di scelte:

	Please type 1 for "first class"
	Please type 2 for "economy class"

Nel caso che il cliente digiti 1, allora il vostro programma dovrà assegnare un posto 
nella sezione prima classe quelli da (1 a 5). Nel caso il cliente digiti digiti 2,
allora il vostro programma dovrà assegnare un posto nella sezione seconda classe quelli da
(6 a 10). Il vostro programma dovrà quindi stampare una carta di imbarco, che dovrà 
indicare il numero di posto assegnato al passseggero e la rispettiva classe del posto.
Utilizzate un vettore unidimensionale per rappresentare la mappa dei posti sull'aereo.
Azzerate tutti gli elementi del vettore in modo da indicare che tutti i posti sono
vuoti. Man mano che i posti saranno assegnati impostere a 1 l'elemento corripondente
del vettore in modo da indicare che il posto non è più disponibile. 
Naturalmente il vostro programma non dovrà mai assegnare un posto che sia stato 
già assegnato. Quando la sezione prima classe sarà piena, il vostro programma dovrà
chiedere al cliente se sia disposto ad accettare una sistemazione nella classe economica
o viceversa. Eseguite l'apporpiata assegnazione del posto  qualora la risposta sia 
affermativa. Visualizzare il messaggio "Next flight leaves in 3 hours", qualora 
la risposta sia negativa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define POSTI 10
#define POSTO_DISPONIBILE 0
#define POSTO_NON_DISPONIBILE 1

void regolamento(int articolo);
void mostraPosti(int arr[], int siz);
void flush(int oggetto);
void stampaBiglietto(int classe, int numeroPosto);

int sceltaPosto();
int sceltaClasse();
int controlloPosti(int classe, int arr[], const int siz);
int prenotaPosto(int classe, int arr[], const int siz);

int main(int argc, char const *argv[]){

	// int aereo[POSTI] = {POSTO_DISPONIBILE};
	int aereo[POSTI] = {0,0,0,1,0,1,1};

	int continuaPrenotazione = 1;

	int check_PostiClasse;
	int classeVolo;
	int numeroPosto;

	do{
		system("clear");
		mostraPosti(aereo, POSTI);

		classeVolo = sceltaClasse();
		check_PostiClasse = controlloPosti(classeVolo, aereo, POSTI);

// Controlla se la prima classe è piena e la seconda è disponibile;
		if(check_PostiClasse == 0 && controlloPosti(2, aereo, POSTI) == 2){
			int risposta;
			do{
				puts("Sono disponibili posti nella seconda classe se si vuole\n");
				printf("Vuoi prenotare nella seconda classe ? SI = 1 NO = 0\n");
				scanf("%d", &risposta);
				flush(risposta);
			}while(risposta != 1 && risposta != 0);

			if(risposta == 0){
				puts("Il prossimo volo partirà tra 3 ore\n");
				return 0;
			}

			numeroPosto = prenotaPosto(2,aereo,POSTI);
		
		}

// Ordina sulla prima classe

		if(check_PostiClasse == 1){
			numeroPosto = prenotaPosto(1,aereo,POSTI);
		}

		if(check_PostiClasse == 2){
			numeroPosto = prenotaPosto(2,aereo,POSTI);
		}
	
	
		if(check_PostiClasse == 3){
			puts("Spiacente seconda classe attualmente piena");
			return 0;
		}

		stampaBiglietto(classeVolo, numeroPosto);



		char risposta;

		do{
			puts("Siamo arrivati fino a qui no?, vuoi continuare ad ordinare?");
			printf("y/n : ");
			scanf("%c",&risposta);
		}while(risposta != 'y' && risposta != 'n');

		if(risposta == 'n'){
			continuaPrenotazione = 0;
		}
	
	 check_PostiClasse 	= 0;
	 classeVolo 		= 0;
	 numeroPosto 		= 0;

	
	}while(continuaPrenotazione);


	return 0;
}

void stampaBiglietto(int classe, int numeroPosto){
	system("clear");

	for(int cnt = 0; cnt < 10; cnt++){
		printf("##");
	}

	puts("\n");
	printf("__________\t__________\n\n");
	printf("NOME: GIGI\tCLASSE: %d\n", classe);
	printf("__________\t__________\n");
	printf("\n");
	printf("\tPOSTO NUMERO: %d", numeroPosto);

	printf("\n\n");

	for(int cnt = 0; cnt < 10; cnt++){
		printf("##");
	}
	sleep(4);

}

int prenotaPosto(int classe, int arr[], const int siz){

	int check_Posto;
	int checkLoop = 1;

// 1 Prima classe | 2 Seconda classe


	if(classe == 1){
		do{
			system("clear");
			mostraPosti(arr,POSTI);
			puts("DPB: Posto disponibile  || NDP: Posto non disponibile\n");

			printf("Quale posto vuoi prenotare? inserire numero posto: ");
			scanf("%d", &check_Posto);
			flush(check_Posto);

			if(check_Posto < 5){

				if(arr[check_Posto - 1] == 1){
					puts("Posto non disponibile inserirne un altro !");
					sleep(2);
				}
				if(arr[check_Posto - 1] == 0){
					puts("Posto prenotato con successo !");
					checkLoop = 0;
					arr[check_Posto - 1] = 1;
					sleep(2);
				}
			} else {
				puts("Classe sbaglita !");
					sleep(2);
			}

		}while(checkLoop);
	}

	if(classe == 2){
		do{
			system("clear");
			mostraPosti(arr, POSTI);
			puts("DPB: Posto disponibile  || NDP: Posto non disponibile\n");

			printf("Quale posto vuoi prenotare? inserire numero posto: ");
			scanf("%d", &check_Posto);
			flush(check_Posto);
			if(check_Posto > 5){

				if(arr[check_Posto - 1] == 1){
					puts("Posto non disponibile inserirne un altro !");
					sleep(2);
				}
				if(arr[check_Posto - 1] == 0){
					puts("Posto prenotato con successo !");
					checkLoop = 0;
					arr[check_Posto - 1] = 1;
					sleep(2);
				}
			} else {
				puts("Classe sbaglita !");
				sleep(2);
			}

		}while(checkLoop);
	}

	return check_Posto;

}


void mostraPosti(int arr[], int siz){
	system("clear");
	for(int cnt = 0; cnt < siz; cnt++){
		if(cnt < 1){
			puts("________________");
			puts("\nPRIMA CLASSE");
			puts("________________");
			puts("\n");
		}
		if(cnt == 5){
			puts("________________");
			puts("\nCLASSE ECONOMICA");
			puts("________________");
			puts("\n");
		}

		if(arr[cnt] == POSTO_DISPONIBILE){ printf("DPB "); }
		if(arr[cnt] == POSTO_NON_DISPONIBILE){ printf("NDP "); }

		printf("  | %d |  POSTO NR: %d\n", arr[cnt], cnt + 1);
	}

	puts("\n\n");
}


int controlloPosti(int classe, int arr[], const int siz){

/*
	0 -> la 1 classe è piena
	1 -> la 1 classe è disponibile
	2 -> la 2 classe è disponibile
	3 -> la 2 classe è piena
*/

	int Posti_PrimaClasse;
	int Posti_ClasseEconomica;

	int cntClasse_1 = (siz / 2) - 1;
	int cntClasse_2 = siz;

// Controllo prima classe

	if(classe == 1){
		for(int cnt = 0; cnt < cntClasse_1; cnt++){
			if(arr[cnt] == 1){
				++Posti_PrimaClasse;
			}
		}
		if(Posti_PrimaClasse == 5){
			printf("La prima classe è piena\n");
			return 0;			
		} else {
			return 1;
		}
	}

	if(classe == 2){
		for(int cnt = 5; cnt < cntClasse_2; cnt++){
			if(arr[cnt] == 1){
				++Posti_ClasseEconomica;
			}
		}

		if(Posti_ClasseEconomica == 5){
			printf("La seconda classe sfortunatamente è tutta occupata\n");
			return 3;
		}else {
			return 2;
		}
	}

	return -1;

} 

int sceltaClasse(){

	int classe;

	do{
		regolamento(0); // Chiede all'utente di scegliere la prenotazione 
		printf("Prenota Classe : ");
		scanf("%d", &classe);
		flush(classe);
		system("clear");

	}while(classe != 1 && classe != 2);

	return classe;

}

void regolamento(int articolo){
	switch(articolo){
		case 0:
			puts("Premere 1 per la prima classe");
			puts("Premere 2 per la classe economica");
			puts("\n");
		break;

		case 1: 
		break;
	}
}

void flush(int oggetto){
	while(oggetto != '\n' && getchar() != '\n');
}
