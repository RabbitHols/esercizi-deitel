/*
 * @Author: Robert Turturica 
 * @Date: 2018-05-22 21:39:50 
 * @Last Modified by: Robert
 * @Last Modified time: 2018-05-22 22:50:34
 */

// Funzione
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


#define NPLAYER 3
#define ROW 5
#define CLM 2

//prototipi


bool doppiaCoppia(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool poker(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool colore(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool tris(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool scala(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool coppia(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool cartaAlta(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);


void shuffle(int[][13]);
void deal(int (*)[], char *[], char *[]);

void sortMani(char * [NPLAYER][ROW][CLM], char *[], int[NPLAYER][ROW][CLM]);
void mostraMano(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);
void manoGiocatori(int (*)[], char *[], char *[], int[][2]);
void giveCardsCoord(char * [NPLAYER][ROW][CLM], int[][CLM], char *[], char *[]);
void controlloMano(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);

int cartaMaggiore(int[NPLAYER][ROW][CLM], int, int, int);

