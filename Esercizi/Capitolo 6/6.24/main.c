/**

Salto del cavallo

**/
#include "header.h"
	
int main()
{
	
	int board[8][8] = {{0}};
	
	/*Posizione attuale asse x y*/
	int pos_x = 0;
	int pos_y = 0;
	
	/*Punto da dove inizio a muovermi con il cavallo*/
	board[pos_x][pos_y] = 1;
	
	muoviCavallo(board, 8, &pos_x, &pos_y);
	
	return 0;
}

