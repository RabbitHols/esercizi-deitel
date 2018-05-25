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

bool doppiaCoppia   (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool poker          (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool colore         (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool tris           (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool scala          (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool coppia         (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool cartaAlta      (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);

void shuffle        (int[][13]);
void deal           (int (*)[], char *[], char *[]);

void sortMani       (char * [NPLAYER][ROW][CLM], char *[], int[NPLAYER][ROW][CLM]);
void mostraMano     (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);
void manoGiocatori  (int (*)[], char *[], char *[], int[][2]);
void giveCardsCoord (char * [NPLAYER][ROW][CLM], int[][CLM], char *[], char *[]);
void controlloMano  (char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);

int cartaMaggiore   (int [NPLAYER][ROW][CLM], int, int, int);

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
    int mazzoMischiato[NPLAYER * ROW][2];

    for (card = 1; card <= 52; card++)
    {
        for (row = 0; row <= 3; row++)
        {
            for (column = 0; column <= 12; column++)
            {
                if (wDeck[row][column] == card)
                {
                    // Catturo i risultati nell'array
                    mazzoMischiato[r][0] = row;
                    mazzoMischiato[r][1] = column;
                    r++;
                }
            }
        }
    }

    manoGiocatori(wDeck, wFace, wSuit, mazzoMischiato);

    return;
}

void manoGiocatori(int wDeck[][13],
                   char *wFace[],
                   char *wSuit[],
                   int hand[][2])
{

    char *manoGiocatore[NPLAYER][ROW][CLM];
    int sortOrder[NPLAYER][ROW][CLM];

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
                     int idPlayer) = {poker, colore, scala, tris, doppiaCoppia, coppia, cartaAlta};

    int combinazioneMaggiore[NPLAYER][2];
    puts("\n\n");

    int key = 0;
    for (int tab = 0; tab < NPLAYER; tab++)
    {
        printf("La mano del giocatore %d  :", tab + 1);

        for (int x = 0; x < 7; x++)
        {
            if ((*check[x])(manoGiocatore, sortOrder, tab))
            {
                switch (x)
                {
                case 0:
                    puts("POKER");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
                    key++;
                    break;

                case 1:
                    puts("COLORE");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
                    key++;
                    break;

                case 2:
                    puts("SCALA");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
                    key++;
                    break;

                case 3:
                    puts("TRIS");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
                    key++;
                    break;

                case 4:
                    puts("DOPPIA COPPIA");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
                    key++;
                    break;

                case 5:
                    puts("COPPIA");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
                    key++;
                    break;
                case 6:
                    puts("CARTA ALTA");
                    combinazioneMaggiore[tab][0] = x;
                    combinazioneMaggiore[tab][1] = tab;
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

    //TESTING: Implementazione incompleta, leggere la descrizione sotto per capire cosa si sta facendo

    //TODO: Scelta vincitore
    /*  La scelta vincitore va gestita in questa maniera, vince chi ha la variabile più bassa,
        essa viene assegnata durante il controllo del true delle funzione in ordine di importanza
        dunque la più bassa ha il valore più alto.
        In ogni funzione implemento un sort personalizzato delle carte in modo da ordinarle in base
        all'importanza della mano 
        ES: COPPIA:
            le carte che rendono la mano coppia le metto per prime e poi ordino le altre in ordine
            di grandezza (kicker).

        In caso la mano fosse uguale devo implementare anche un assegnazione del valore dei colori
        dal più importante al meno
    */

    int vincitore[1][2];
    vincitore[0][0] = combinazioneMaggiore[0][0];
    vincitore[0][1] = combinazioneMaggiore[0][1];

    for(int n = 1; n < NPLAYER; n++)
    {
        if( vincitore[0][0] > combinazioneMaggiore[n][0] )
        {
            vincitore[0][0] = combinazioneMaggiore[n][0];
            vincitore[0][1] = combinazioneMaggiore[n][1];
            continue;
        }

         if( vincitore[0][0] == combinazioneMaggiore[n][0] && ( vincitore[0][0] == 6 || vincitore[0][0] == 5  ) )
         {
             int winner = cartaMaggiore(sortOrder, vincitore[0][1], n, 0);
             if(winner == combinazioneMaggiore[n][1])
             {
                 vincitore[0][0] = combinazioneMaggiore[n][0];
                 vincitore[0][1] = combinazioneMaggiore[n][1];
             }

         }

    }

    printf("Il vincitore e' il giocatore nr %d", vincitore[0][1] + 1);

}

int cartaMaggiore(int sortOrder[NPLAYER][ROW][CLM],
                  int idPlayer_1, 
                  int idPlayer_2,
                  int cont)
{
    if(cont == 4)
    {
        return (sortOrder[idPlayer_1][cont][0] > sortOrder[idPlayer_2][cont][0]) ? idPlayer_1 : idPlayer_2; 
    }

    if(sortOrder[idPlayer_1][cont][0] == sortOrder[idPlayer_2][cont][0])
    {
        return cartaMaggiore(sortOrder, idPlayer_1, idPlayer_2, cont + 1);
    }

    return (sortOrder[idPlayer_1][cont][0] > sortOrder[idPlayer_2][cont][0]) ? idPlayer_1 : idPlayer_2;
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

bool scala(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
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

bool poker(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
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

bool colore(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
{
    int colore_1 = strcmp(manoGiocatori[idPlayer][0][1], manoGiocatori[idPlayer][1][1]);
    int colore_2 = strcmp(manoGiocatori[idPlayer][1][1], manoGiocatori[idPlayer][2][1]);
    int colore_3 = strcmp(manoGiocatori[idPlayer][2][1], manoGiocatori[idPlayer][3][1]);
    int colore_4 = strcmp(manoGiocatori[idPlayer][3][1], manoGiocatori[idPlayer][4][1]);

    if (!colore_1 && !colore_2 && !colore_3 && !colore_4)
    {
        return true;
    }

    return false;
}

bool tris(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
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

bool doppiaCoppia(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
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

bool coppia(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
{

    int temp_1;
    int temp_2;

    for (int f = 0; f < 4; f++)
    {
        for (int c = f + 1; c < 5; c++)
        {
            if (sortOrder[idPlayer][f][0] == sortOrder[idPlayer][c][0])
            {           
    /*
                Se trova una coppia sorta la coppia ai primi 2 posti e il restante dei kicker in ordine decrescente              
    */

                int arr[5][2] = { -1 };

                arr[0][0] = sortOrder[idPlayer][f][0];
                arr[0][1] = sortOrder[idPlayer][f][1];

                arr[1][0] = sortOrder[idPlayer][c][0];
                arr[1][1] = sortOrder[idPlayer][c][1];

                for(int n = 2, k = 0; n < 5; n++, k++)
                {
                    if(sortOrder[idPlayer][k][0] == arr[0][0])
                    {   k++;
                        n--;
                        continue;
                    }

                    arr[n][0] = sortOrder[idPlayer][k][0];
                    arr[n][1] = sortOrder[idPlayer][k][1];
                }

                temp_1 = arr[2][0];
                arr[2][0] = arr[4][0];
                arr[4][0] = temp_1;  

                
                temp_2 = arr[2][1];
                arr[2][1] = arr[4][1];
                arr[4][1] = temp_2;  
            
                for(int n = 0; n < ROW; n++)
                {
                    sortOrder[idPlayer][n][0] = arr[n][0];
                    sortOrder[idPlayer][n][1] = arr[n][1];
                }

                return true;
            }
        }
    }

    
    return false;
}

bool cartaAlta(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
{

    int temp_1;
    int temp_2;

    int n = 0;
    int k = 4;
    while(n != 2)
    {   

        temp_1 = sortOrder[idPlayer][n][0];
        temp_2 = sortOrder[idPlayer][n][1];

        sortOrder[idPlayer][n][0] = sortOrder[idPlayer][k][0];
        sortOrder[idPlayer][n][1] = sortOrder[idPlayer][k][1];

        sortOrder[idPlayer][k][0] = temp_1;
        sortOrder[idPlayer][k][1] = temp_2;

        k--;
        n++;
    }

    return true;
}
