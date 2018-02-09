/*

Algoritmo iterativo per risolvere le torri di hanoi

L'algoritmo funziona perfettamente con 3 torri, ma è da perfezionare con le 4

TODO: 
	# Cercare di sbarazzarci dello zero che ci rovina l'intero array, dovrei farlo di char
	  e usare gli spazi al posto degli zero. ! LA VEDO DURA 

	# Rendere l'array funzionante con numeri di cerchi differeti dal 3, attualmente il 
	  metodo sarebbe di scambiare 3 con il 2.	

TOFIX:
	# Praticamente per colpa dello zero l'uno rimane stallato. Devo aggiustare l'algoritmo.

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int PL_1 = 0;
const int PL_2 = 1;
const int PL_3 = 2;

#define DM_STCK 3
#define DM_CLMN 3

void print(int STCK[][DM_STCK], int DM_S);

void MOV_PL(int STCK[][DM_STCK], int FROM, int TO, size_t DM_S);
int CHK_POS_FROM(int STCK[][DM_STCK], int N_PL, size_t DM_S);
int CHK_POS_TO(int STCK[][DM_STCK], int N_PL, size_t DM_S);
int CHK_STK(int STCK[][DM_STCK], int N_PL, size_t DM_S);


int main(){

	
	int stack[][DM_STCK] = { {1,0,0},
					   		 {2,0,0},
					   		 {3,0,0}, 
					   		 {4,0,0},
					   		 {5,0,0}};

	int mosse = pow(2,DM_CLMN) - 1;

	print(stack, DM_STCK);

	for(int cnt = 0; cnt < mosse; cnt++){

		int RS_1 = 0;
		int RS_2 = 0;

		printf("MOSSA NUMERO: %d\n", cnt);

		if(cnt % 3 == 0){

			RS_1 = CHK_STK(stack, PL_1, DM_CLMN);
			RS_2 = CHK_STK(stack, PL_3, DM_CLMN);

				RS_1 = CHK_STK(stack, PL_2, DM_CLMN);
				RS_2 = CHK_STK(stack, PL_3, DM_CLMN);

				if(RS_1 > RS_2){
					if(RS_2 == 0){
					MOV_PL(stack, PL_1, PL_3, DM_CLMN);
					//printf("A --> B");
					} else {
						ODINO_0:
						MOV_PL(stack, PL_3, PL_1, DM_CLMN);
					//printf("B --> A");
					}
				} if(RS_1 < RS_2) {
					if(RS_1 == 0){
						goto ODINO_0;
					}
					MOV_PL(stack, PL_1, PL_3, DM_CLMN);
				}

			}

		if(cnt % 3 == 1){

				RS_1 = CHK_STK(stack, PL_2, DM_CLMN);
				RS_2 = CHK_STK(stack, PL_3, DM_CLMN);

				if(RS_1 > RS_2){
					if(RS_2 == 0){
					MOV_PL(stack, PL_1, PL_2, DM_CLMN);
					//printf("A --> B");
					} else {
//					Che odino sia con me
					ODINO_1:
					MOV_PL(stack, PL_2, PL_1, DM_CLMN);
					//printf("B --> A");
					}
				} else {
					if(RS_1 == 0){
						goto ODINO_1;
					}
					MOV_PL(stack, PL_1, PL_2, DM_CLMN);
				}
		}

		if(cnt % 3 == 2){

			RS_1 = CHK_STK(stack, PL_2, DM_CLMN);
			RS_2 = CHK_STK(stack, PL_3, DM_CLMN);

				if(RS_1 > RS_2){
					if(RS_2 == 0){
					MOV_PL(stack, PL_2, PL_3, DM_CLMN);
					//printf("A --> B");
					} else {
					ODINO_2:
					MOV_PL(stack, PL_3, PL_2, DM_CLMN);
					//printf("B --> A");
					}
				} else {
					if(RS_1 == 0){
						goto ODINO_2;
					}
					MOV_PL(stack, PL_2, PL_3, DM_CLMN);
				}
		}

			RS_1 = 0;
			RS_2 = 0;

			print(stack, DM_STCK);

	}


	return 0;
}

// Stampa le 3 torri

void print(int STCK[][DM_STCK], int DM_S){
	for(int colonne = 0; colonne < DM_CLMN; colonne++){
		for(int righe = 0; righe < DM_STCK; righe++){
			printf("%d ", STCK[colonne][righe]);
		}
		puts("\n");
	}

	puts("\n");
}

// Controlla in che direzione muovere il paletto se -> o <-

void MOV_PL(int STCK[][DM_STCK], int FROM, int TO, size_t DM_S){

	int POS_1 = CHK_POS_FROM(STCK, FROM, DM_S);
	int POS_2 = CHK_POS_TO(STCK, TO,DM_S);

	int TMP = STCK[POS_2][TO];
	STCK[POS_2][TO] = STCK[POS_1][FROM];
	STCK[POS_1][FROM] = TMP;

}

// Estrae la posizione del numero da posizione

int CHK_POS_FROM(int STCK[][DM_STCK], int N_PL, size_t DM_S){
	
	int POS = DM_S - 1;

	for(int cnt_1 = 0; cnt_1 < DM_S; cnt_1++){
    	if(STCK[cnt_1][N_PL] != 0){
   	       POS = cnt_1;
      	   break;
      }
    }


    return POS;

}

/* 
	 Estrae la posizione di dove posizione il numero da posizione e 
	controlla che non sia uno zero, se non è uno zero allora è pos - 1 altrimenti 
	solo pos
*/

int CHK_POS_TO(int STCK[][DM_STCK], int N_PL, size_t DM_S){
	
	int POS = DM_S - 1;

	for(int cnt_1 = 0; cnt_1 < DM_S; cnt_1++){
    	if(STCK[cnt_1][N_PL] != 0){
   	       POS = cnt_1 - 1;
      	   break;
      }
    }

   
    return POS;

}

/*
	
	Estra il primo anello dallo stack e lo confronta con l'anello del l'altro stack
	per decidere in quale verso spostare l'anello.

*/ 

int CHK_STK(int STCK[][DM_STCK], int N_PL, size_t DM_S){

	int FLG = 0;

	for(int cnt = 0; cnt < DM_S; cnt++){
    	if(STCK[cnt][N_PL] != 0){
   	       FLG = STCK[cnt][N_PL];
      	break;
      }
    }
  
 return FLG;

}

