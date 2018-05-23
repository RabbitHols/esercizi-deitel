/*
 * @Author: Robert Turturica 
 * @Date: 2018-05-22 21:39:50 
 * @Last Modified by: Robert
 * @Last Modified time: 2018-05-22 22:50:34
 */

// Funzioni
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define NPLAYER 3
#define ROW 5
#define CLM 2

//prototipi

bool doppiaCoppia   (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );
bool poker          (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );
bool colore         (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );
bool tris           (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );
bool scala          (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );
bool coppia         (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );
bool cartaAlta      (char * [NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM], int , int [] );

void shuffle        (int[][13]);
void deal           (int (*)[], char *[], char *[]);

void sortMani       (char * [NPLAYER][ROW][CLM], char *[], int[NPLAYER][ROW][CLM]);
void mostraMano     (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);
void manoGiocatori  (int (*)[], char *[], char *[], int[][2]);
void giveCardsCoord (char * [NPLAYER][ROW][CLM], int[][CLM], char *[], char *[]);
void controlloMano  (char *[NPLAYER][ROW][CLM], int [NPLAYER][ROW][CLM]);

// Mescola carte
void shuffle(int wDeck[][13])
{
    int row;
    int column;
    int card;

    for (card = 1; card <= 52; card++)
    {
        do
        {
            row = rand() % 4;
            column = rand() % 13;
        } while (wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
    return;
}

void deal(int wDeck[][13],
          char *wFace[],
          char *wSuit[])
{

    int card;
    int row;
    int column;

    int r = 0;
    // hand usato per catturare le prime carte in base a quanti giocatori vi sono
    int hand[NPLAYER * ROW][2];

    for (card = 1; card <= 52; card++)
    {
        for (row = 0; row <= 3; row++)
        {
            for (column = 0; column <= 12; column++)
            {
                if (wDeck[row][column] == card)
                {
                    // Catturo i risultati nell'array
                    if (r < 52)
                    {
                        hand[r][0] = row;
                        hand[r][1] = column;
                        r++;
                    }
                }
            }
        }
    }

    //  manoAttuale(wDeck, wFace, wSuit, hand);

    manoGiocatori(wDeck, wFace, wSuit, hand);

    return;
}

void manoGiocatori(int wDeck[][13],
                   char *wFace[],
                   char *wSuit[],
                   int hand[][2])
{

    char *manoGiocatore[NPLAYER][ROW][CLM];
    int sortOrder[NPLAYER][ROW][CLM];

    //  TODO:  In caso di pareggio uso questa funzione per ricavarmi il giocatore con la carta più alta
    //  TODO:  Fare una funzione che controlli il pareggio

    // Nel primo elemento vediamo cosa è uscito nel secondo la carta più alta in caso di parità

    system("cls");

    giveCardsCoord(manoGiocatore, hand, wFace, wSuit);

    sortMani(manoGiocatore, wFace, sortOrder);

    mostraMano(manoGiocatore, sortOrder);

    controlloMano(manoGiocatore, sortOrder);

    return;
}

void controlloMano(char *manoGiocatore[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM])
{
    bool (*check[7])(char *manoGiocatore[NPLAYER][ROW][CLM],
                     int sortOrder[NPLAYER][ROW][CLM],
                     int idPlayer,
                     int maxValore[]) = {poker, colore, scala, tris, doppiaCoppia, coppia, cartaAlta};

    int manoMaggiore[NPLAYER];

    puts("\n\n");

    int key = 0;
    for(int tab = 0; tab < NPLAYER; tab++)
    {
        printf("La mano del giocatore %d  :", tab + 1);

        for (int x = 0; x < 7; x++)
        {
            if ((*check[x])(manoGiocatore, sortOrder, tab, manoMaggiore))
            {
                switch (x)
                {
                case 0:
                    puts("POKER");
                    manoMaggiore[tab] = x;
                    key++;
                    break;

                case 1:
                    puts("COLORE");
                    manoMaggiore[tab] = x;
                    key++;
                    break;

                case 2:
                    puts("SCALA");
                    manoMaggiore[tab] = x;
                    key++;
                    break;

                case 3:
                    puts("TRIS");
                    manoMaggiore[tab] = x;
                    key++;
                    break;

                case 4:
                    puts("DOPPIA COPPIA");
                    manoMaggiore[tab] = x;
                    key++;
                    break;

                case 5:
                    puts("COPPIA");
                    manoMaggiore[tab] = x;
                    key++;
                    break;
                case 6:
                    puts("CARTA ALTA");
                    manoMaggiore[tab] = x;
                    key++;
                    break;
                default:
                    puts("ERROR");
                    break;
                }
            }
            if (key)
                break;
        }
        key = 0;
        puts("");
    }

    /* TODO: Implementare un sistema migliore di vincita
    Il sistema deve rendersi conto di chi ha la carta maggiore tra gli n giocatori e 
    stampare su terminale il vincitore */

    if(manoMaggiore[0] < manoMaggiore[1])
    {
        if(manoMaggiore[0] < manoMaggiore[2])
        {
            puts("### IL GIOCATORE 1 HA VINTO ! ###");
        }
        else{
             puts("### IL GIOCATORE 3 HA VINTO ! ###");
        }
    }
    else
    {
        if(manoMaggiore[1] < manoMaggiore[2])
        {
            puts("### IL GIOCATORE 2 HA VINTO ! ###");
        }
        else{
             puts("### IL GIOCATORE 3 HA VINTO ! ###");
        }
    }


}

//  Assegno alla mano del giocatore le carte e le coordinate delle carte estratte dal mazzo.
void giveCardsCoord(char *manoGiocatore[NPLAYER][ROW][CLM], int hand[][CLM], char *wFace[], char *wSuit[])
{
    int carta = 0;

    for (int tab = 0; tab < NPLAYER; tab++)
    {
        for (int riga = 0; riga < ROW; riga++, carta++)
        {
            manoGiocatore[tab][riga][0] = wFace[hand[carta][1]];
            manoGiocatore[tab][riga][1] = wSuit[hand[carta][0]];
        }
    }
}

// Stampla le mani dei giocatori

void mostraMano(char *manoGiocatore[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM])
{
    for (int tab = 0; tab < NPLAYER; tab++)
    {
        printf("\n \nMANO GIOCATORE %d\n\n", tab + 1);
        for (int x = 0; x < ROW; x++)
        {
            int n = sortOrder[tab][x][1];
            printf("%s ", manoGiocatore[tab][n][0]);
            printf("%s \n", manoGiocatore[tab][n][1]);
        }
    }
}

void sortMani(char *manoGiocatori[NPLAYER][ROW][CLM], char *wFace[], int sortOrder[NPLAYER][ROW][CLM])
{
    for (int tab = 0; tab < NPLAYER; tab++)
    {
        for (int ncarte = 0; ncarte < ROW; ncarte++)
        {
            for (int x = 0; x < 13; x++)
            {
                if (strcmp(manoGiocatori[tab][ncarte][0], wFace[x]) == 0)
                {
                    sortOrder[tab][ncarte][0] = x + 1;
                    sortOrder[tab][ncarte][1] = ncarte;
                }
            }
        }
    }

    // Insertion Sort

    for (int tab = 0; tab < NPLAYER; tab++)
    {
        for (int c = 0; c < ROW - 1; c++)
        {
            int s = c;
            while (sortOrder[tab][s][0] > sortOrder[tab][s + 1][0])
            {
                for (int c = 0; c < 2; c++)
                {
                    int key = sortOrder[tab][s][c];
                    sortOrder[tab][s][c] = sortOrder[tab][s + 1][c];
                    sortOrder[tab][s + 1][c] = key;
                }
                if (s == 0)
                    break;
                s--;
            }
        }
    }

    return;
}

/*
 * Scala controlla se la carta successiva -1 è uguale a quella precedente
 * se cosi non è allora non è scala
 */


bool scala(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{
    for (int k = 0; k < 4; k++)
    {
        if (sortOrder[idPlayer][k][0] != (sortOrder[idPlayer][k + 1][0] - 1))
        {
            return false;
        }
    }

    return true;
}

bool poker(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{
    int carta_1 = sortOrder[idPlayer][0][0];
    int carta_2 = sortOrder[idPlayer][1][0];
    int carta_3 = sortOrder[idPlayer][2][0];
    int carta_4 = sortOrder[idPlayer][3][0];

    if (carta_1 == carta_2 && carta_2 == carta_3 && carta_3 == carta_4)
    {
        return true;
    }

    return false;
}

/*
 * Uso la funziona string compare per vedere se le carte sono dello stesso colore,
 * se lo sono string compare mi restituisce zero. Dunque controllo nell'if che tutti
 * i valori siano zero.
 * */

bool colore(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{
    int colore_1 = strcmp(manoGiocatori[idPlayer][0][1], manoGiocatori[idPlayer][1][1]);
    int colore_2 = strcmp(manoGiocatori[idPlayer][1][1], manoGiocatori[idPlayer][2][1]);
    int colore_3 = strcmp(manoGiocatori[idPlayer][2][1], manoGiocatori[idPlayer][3][1]);
    int colore_4 = strcmp(manoGiocatori[idPlayer][3][1], manoGiocatori[idPlayer][4][1]);

    if (colore_1 == 0)
    {
        return colore_1 && colore_2 == 0 && colore_3 == 0 && colore_4 == 0;
    }

    return false;
}

bool tris(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{

    int arr[5] = {sortOrder[idPlayer][0][0], sortOrder[idPlayer][1][0],
                  sortOrder[idPlayer][2][0], sortOrder[idPlayer][3][0],
                  sortOrder[idPlayer][4][0]};

    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[3] != arr[4])
    {
        return true;
    }

    if (arr[1] == arr[2] && arr[2] == arr[3] && arr[4] != arr[0])
    {
        return true;
    }

    if (arr[2] == arr[3] && arr[3] == arr[4] && arr[0] != arr[1])
    {
        return true;
    }

    return false;
}

bool doppiaCoppia(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{
    int arr[5] = {sortOrder[idPlayer][0][0], sortOrder[idPlayer][1][0],
                  sortOrder[idPlayer][2][0], sortOrder[idPlayer][3][0],
                  sortOrder[idPlayer][4][0]};

    if (arr[0] != arr[1] && arr[0] != arr[2] && arr[1] == arr[2] && arr[3] == arr[4] && arr[1] != arr[4])
    {
        return true;
    }

    if (arr[0] == arr[1] && arr[1] != arr[2] && arr[2] != arr[3] && arr[3] == arr[4] && arr[4] != arr[0])
    {
        return true;
    }

    if (arr[0] == arr[1] && arr[2] == arr[3] && arr[4] != arr[0] && arr[4] != arr[2] && arr[2] != arr[1])
    {
        return true;
    }

    return false;
}

bool coppia(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{
    int arr[5] = {sortOrder[idPlayer][0][0], sortOrder[idPlayer][1][0],
                  sortOrder[idPlayer][2][0], sortOrder[idPlayer][3][0],
                  sortOrder[idPlayer][4][0]};

    for (int f = 0; f < 4; f++)
    {
        for (int c = f + 1; c < 5; c++)
        {
            if (arr[f] == arr[c])
            {
                return true;
            }
        }
    }

    return false;
}

bool cartaAlta(char * manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer, int maxValore[])
{
    return true;
}
