/**

Salto del cavallo

**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SIZE 8

int floor_Board[SIZE][SIZE] = { {0} };

/** I VARI MOVIMENTI DEL CAVALLO **/
int x[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
int y[8] = {+1,+2,+2,+1,-1,-2,-2,-1};

void decisioni	(void);
void decisione_mossa(void);
void cflush		(void);
void p_board 	(int floor_Board[][SIZE]);
void horse_m 	(int muovi_x, int muovi_y);
int checkWin	(void);

void rand_move	(void);

int X = 4;
int Y = 4;

int main(int argc, char const *argv[])
{	
	srand(time(NULL));

	floor_Board[X][Y] = 1;
	
/**
	decisioni();
**/

	for(int cnt = 0; cnt < 10000; cnt++){
		p_board(floor_Board);
		rand_move();
		usleep(10000);
	}

	return 0;
}



void
rand_move()
{	

	int muovi_x = 2 - ( rand() % 4);
	int muovi_y = 2 - ( rand() % 4);

	int pos_x = X + muovi_x;
	int pos_y = Y + muovi_y;

	if(pos_x > -1 && pos_x < 8){
		if(pos_y > -1 && pos_y < 8){
			X = X + (muovi_x);
			Y = Y + (muovi_y);
			floor_Board[X][Y] = 1;
			return;
		}
	}

	
}

int 
checkWin(void)
{
	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			if(floor_Board[x][y] != 1 ){
				return 1;
			}
		}
	}

	return 0;

}

void 
decisione_mossa(void){
	int direzione;
	puts("In che direzione desideri andare con il cavallo ?");
	puts("0 :\t NORD 	- EST");
	puts("1 :\t EST  	- NORD");
	puts("2 :\t EST  	- SUD");
	puts("3 :\t SUD  	- EST");
	puts("4 :\t SUD  	- OVEST");
	puts("5 :\t OVEST 	- SUD");
	puts("6 :\t OVEST 	- NORD");
	puts("7 :\t NORD	- OVEST");

	scanf("%d", &direzione);
	cflush();

	switch(direzione){
		case 0: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 1: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 2: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 3: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 4: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 5: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 6: 
			horse_m(x[direzione], y[direzione]);
			break;

		case 7: 
			horse_m(x[direzione], y[direzione]);
			break;

		default:
			puts("Mossa inesistenze");
			break;

	}

}

void 
decisioni(void)
{
	int state = 1;

	

	while(state){

		p_board(floor_Board);


		puts("COSA VUOI FARE ?\n");
		puts("1 :\t MUOVITI SULLA SCACCHIERA");
		puts("2 :\t ESCI");

		scanf("%d", &state);
		cflush();

		switch(state){
			case 1:
				decisione_mossa();
				break;

			case 2:
				state = 0;
				break;

			default:
				puts("Mossa non valida");
				break;
		}

		checkWin();
	}

}


void 
horse_m(int muovi_x, int muovi_y)
{	


	int pos_x = X + (muovi_x);;
	int pos_y = Y + (muovi_y);

	if(pos_x > -1 && pos_x < 8){
		if(pos_y > -1 && pos_y < 8){
			X = X + (muovi_x);
			Y = Y + (muovi_y);
			floor_Board[X][Y] = 1;
			return;
		}
	}

	puts("\n #### MOSSA NON VALIDA !  #### \n");
	sleep(1);

}

void
p_board(int arr[][SIZE])
{
	system("clear");

	printf("\n  ");
	for(int x = 0; x < 8; x++){
		printf(" %d ", x);
	}
	puts("");
	for(int row = 0; row < SIZE; row++){
		printf("%d ", row);
		for(int clm = 0; clm < SIZE; clm++){
			if(arr[row][clm] == 0){
				printf("[ ]");
			} else {
				printf("[C]");
			}

		}
		puts("");
	}

	puts("\n");

}

void
cflush(void)
{
	int ogg;
	while( ( ogg = getchar() ) != '\n' && ogg != EOF);
}