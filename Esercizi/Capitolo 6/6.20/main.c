/*

Implementare il gioco dei dadi crips

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define IN_CORSO 1
#define FINITO 0

#define PASS_LINE 1
#define DONT_PASS 0

#define PASS_LINE_VINTO 1
#define DONT_PASS_VINTO 2
#define DONT_PASS_PAREG 3



int lanciaDadi();
int sceltaScommessa();
int controllaRisultato(int risultatoLancio);

void stampaRegole(int numeroRegola);
void flush(int);

int main(int argc, char const *argv[]){
	
	srand(time(NULL));

	int risultatoLancio;
	int risultatoLancioSuccessivo;
	int decisione;
	int num_regola;
	int check; // fa il check su chi ha vinto e perso

	int StatoDelGioco = IN_CORSO;

	while(StatoDelGioco == IN_CORSO){
		stampaRegole(0);
		decisione = sceltaScommessa();

		stampaRegole(1);
		sleep(1);
		system("clear");

		num_regola = (decisione == 1) ? PASS_LINE : DONT_PASS;
		stampaRegole(num_regola);

		risultatoLancio = lanciaDadi();

		printf("NUMERO USCITO : %d\n\n", risultatoLancio);

		puts("STO CONTROLLANDO IL RISULTATO\n");
		sleep(3);

		// system("clear");
		

		check = controllaRisultato(risultatoLancio);

		if(check == 0 || check == 1 || check == 2){ 
			//StatoDelGioco == FINITO;
			break;
		}

		while(StatoDelGioco == IN_CORSO){
			system("clear");
			stampaRegole(8);

			risultatoLancioSuccessivo = lanciaDadi();

			printf("NUMERO PRIMA : %d\n\n", risultatoLancio);
			printf("NUMERO ADESSO : %d\n\n", risultatoLancioSuccessivo);

			puts("STO CONTROLLANDO IL RISULTATO\n");
			sleep(3);

			if(risultatoLancioSuccessivo == risultatoLancio){
				stampaRegole(5);
				StatoDelGioco = FINITO;
				break;
			}
			if(risultatoLancioSuccessivo == 7){
				stampaRegole(6);
				//StatoDelGioco = FINITO;
				break;
			}

			risultatoLancio = risultatoLancioSuccessivo;
		}

		puts("\nGIOCO FINITO VUOI RIGIOCARE?\n\n");


		char rigioca;
	
		do{

		puts("Vuoi rigiocare ? y/n");
		scanf("%c", &rigioca);
		flush(rigioca);
		system("clear");
		}while(rigioca != 'y' && rigioca != 'n');

		if(rigioca == 'n'){
			StatoDelGioco = FINITO;
		}

	} 



	return 0;
}

int controllaRisultato(int risultatoLancio){

	switch(risultatoLancio){

		case 2:
		case 3:
			stampaRegole(6); // DP vince PL perde
			return 0;
		break;

		case 7 :
		case 11 :
			stampaRegole(5); // PL vince e DP perde
			return 1;
		break;

		case 12:
			stampaRegole(7); // DP pareggia con 12 e PL perde
			return 2;
		break;

		default:
			stampaRegole(8); // Il gioco continua
			return 3;
		break;

	}

}

int sceltaScommessa(){
	
	int decisione;

	do{
		puts("\n");
		printf("PASS LINE = 1\n");
		printf("DONT PASS = 0\n\n");

		printf("SCEGLI 1/0 :");
		scanf("%d", &decisione);
		flush(decisione);
		system("clear");
	}while(decisione != 1 && decisione != 0);

	return decisione;

}

void flush(int oggetto){
	while(oggetto != '\n' && getchar() != '\n');
}

void stampaRegole(int numeroRegola){
	switch(numeroRegola){
		case 0:
			puts("### SCEGLI IL TIPO DI PUNTATA ###\n");
			puts("\tPASS LINE  \t|\tDONT PASS  \t\n\n");
		break;

		case 1: 
			puts("### FINE FASE COMING OUT\n");
		break;

		case 2:
			puts("SE ESCE 7 11 PASS LINE VINCE");
			puts("se esce 2 3 12 PASS LINE PERDE");
		break;

		case 3:
			puts("SE ESCE 2 3 DONT PASS VINCE");
			puts("SE ESCE 7 11 DONT PASS PERDE");
		break;

		case 4:
			puts("VIA CON IL LANCIO !\n\n");
		break;

		case 5:
			puts("PASS LINE HA VINTO E DONT PASS HA PERSO !");
		break;

		case 6:
			puts("DONT PASS HA VINTO E PASS LINE HA PERSO !");
		break;

		case 7:
			puts("DONT PASS HA PAREGGIATO E PASS LINE HA PERSO !");
		break;

		case 8:
			puts("IL GIOCO CONTINUA !\n");
		break;
	}
}


int lanciaDadi(){

	int dado_1;
	int dado_2;

	dado_1 = 1 + rand() % 6;
	dado_2 = 1 + rand() % 6;

	return dado_1 + dado_2;
}