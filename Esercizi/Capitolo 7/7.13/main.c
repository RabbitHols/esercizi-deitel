/*
 Created by Robert on 18/05/2018.
*/

// Esercizio 7.13 Mano migliore

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//prototipi


bool poker          ( char * [][2], int [][2], int);
bool colore         ( char * [][2], int [][2], int);
bool tris           ( char * [][2], int [][2], int);
bool scala          ( char * [][2], int [][2], int);
bool doppiaCoppia   ( char * [][2], int [][2], int);
bool coppia         ( char * [][2], int [][2], int);

void shuffle        (int [][13]);
void sortMano       ( char * [][2],char * [], int [][2]);
void deal           ( int (*)[], char * [],  char *[]);
void manoAttuale    ( int (*)[], char * [],  char *[], int [][2]);

int main()
{

    char *suit[4] = {"Di Cuori", "Di Denari", "Di Fiori", "Di Picche"};

    char *face[13] = {"Asso", "Due", "Tre", "Quattro",
                      "Cinque", "Sei", "Seven", "Otto",
                      "Nove", "Dieci", "Regina", "Regina", "Re"};

    int deck[4][13] = {0};

    srand(time(NULL));

    shuffle(deck);

    deal(deck, face, suit);

    return 0;

}

// Mescola carte

void shuffle(int wDeck[][13])
{
    int row;
    int column;
    int card;

    for(card = 1; card <= 52; card++)
    {
        do
        {
            row     = rand() % 4;
            column  = rand() % 13;
        } while(wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
    return;
}

void deal( int   wDeck[][13],
           char *wFace[],
           char *wSuit[] ){

    int card;
    int row;
    int column;

    int r = 0;
    // hand usato per catturare le prime 5 carte e usarle come manoAttuale nel gioco
    int hand[10][2];

    for(card = 1; card <= 52; card++)
    {
        for(row = 0; row <= 3; row++)
        {
            for(column = 0; column <= 12; column++)
            {
                if(wDeck[row][column] == card)
                {
                    // Catturo i primi 5 risultato nell'handay
                    if(r < 10){
                        hand[r][0] = row;
                        hand[r][1] = column;
                        r++;
                    }
                }
            }
        }
    }


    manoAttuale(wDeck, wFace, wSuit, hand);


    return;
}
// TODO: Rifattorizzare il codice suddividere in 2 mani diverse. Rendere scalabile il gioco a più giocatori.
void manoAttuale( int   wDeck[][13],
                  char *wFace[],
                  char *wSuit[],
                  int hand[][2]){

    bool (*check[6]) (char *manoAttuale[][2],
                      int sortOrder[][2],
                      int maxValore) = {  poker, colore, scala, tris, doppiaCoppia, coppia};

    system("cls");

    char * manoAttuale[5][2];
    char * manoDue[5][2];

    int sortOrder[5][2] = { 0 };

    // Variabili usate per vedere quale è' la mano migliore

    int risultato_Mano_1;
    int risultato_Mano_2;

   
/*    
    La variabile maxValore serve a immagazzina il valore della carta che è coppia per confrontarla
    con le altre mani in caso di parità

    TODO: Inserire valore coppia dentro la matrice, creare una matrice [][][]

 */

    int maxValore;

    for(int x = 0; x < 5; x++)
    {
        manoAttuale[x][0] = wFace[hand[x][1]];
        manoAttuale[x][1] = wSuit[hand[x][0]];
    }

    // Sorto la prima mando
    sortMano(manoAttuale, wFace, sortOrder);



    puts("\n### PRIMA MANO ### \n");

    for(int x = 0; x < 5; x++)
    {
        int n = sortOrder[x][1];
        printf("%s ", manoAttuale[n][0]);
        printf("%s \n", manoAttuale[n][1]);
    }

    puts("\n");


    for(int x = 0; x < 6; x++)
    {
        int key = 0;
        if( (*check[x]) (manoAttuale, sortOrder, maxValore) )
        {
            switch(x)
            {
                case 0: puts("POKER"); key++; risultato_Mano_1 = x;
                    break;

                case 1: puts("COLORE"); key++;risultato_Mano_1 = x;
                    break;

                case 2: puts("SCALA"); key++; risultato_Mano_1 = x;
                    break;

                case 3: puts("TRIS"); key++; risultato_Mano_1 = x;
                    break;

                case 4: puts("DOPPIA COPPIA"); key++; risultato_Mano_1 = x;
                    break;

                case 5: puts("COPPIA"); key++; risultato_Mano_1 = x;
                    break;

                default: puts("ERROR");
                    break;
            }
        }
        if(key) break;
    }

    // Do la seconda mano
    for(int x = 0; x < 5; x++)
    {
        manoDue[x][0] = wFace[hand[5 + x][1]];
        manoDue[x][1] = wSuit[hand[5 + x][0]];
    }

    // Sorto la seconda mano
    sortMano(manoDue, wFace, sortOrder);

    puts("\n### SECONDA MANO ### \n");

    for(int x = 0; x < 5; x++)
    {
        int n = sortOrder[x][1];
        printf("%s ", manoDue[n][0]);
        printf("%s \n", manoDue[n][1]);
    }

    puts("\n");

    for(int x = 0; x < 6; x++)
    {
        int key = 0;
        if( (*check[x]) (manoDue, sortOrder, maxValore) )
        {
            switch(x)
            {
                case 0: puts("POKER"); key++; risultato_Mano_2 = x;
                    break;

                case 1: puts("COLORE"); key++;risultato_Mano_2 = x;
                    break;

                case 2: puts("SCALA"); key++; risultato_Mano_2 = x;
                    break;

                case 3: puts("TRIS"); key++; risultato_Mano_2 = x;
                    break;

                case 4: puts("DOPPIA COPPIA"); key++; risultato_Mano_2 = x;
                    break;

                case 5: puts("COPPIA"); key++; risultato_Mano_2 = x;
                    break;

                default: puts("ERROR");
                    break;
            }
        }
        if(key) break;
    }

// TODO: in caso di parità vedere chi la la mano più alta
 
    if(risultato_Mano_1 < risultato_Mano_2)
    {
        printf("MANO 1 HA VINTO\n");
    }
    else if(risultato_Mano_1 > risultato_Mano_2)
    {
        printf("MANO 2 HA VINTO\n");
    }
    else{
        printf("PARI\n");
    }

    return;

}


/*
 * sortMano funziona associando alla parola della carta il suo effettivo valore.
 */

#define UGUALI 0
void sortMano(char * manoAttuale[][2], char *wFace[], int sortOrder[][2])
{

    for(int cnt = 0; cnt < 5; cnt++)
    {
        for(int x = 0; x < 13; x++)
        {
            if(strcmp(manoAttuale[cnt][0], wFace[x]) == UGUALI)
            {
                sortOrder[cnt][0] = x + 1;
                sortOrder[cnt][1] = cnt;
            }
        }
    }

    for(int c = 0; c < 5 - 1; c++)
    {
        int s = c;
        while(sortOrder[s][0] > sortOrder[s + 1][0])
        {
            for(int c = 0; c < 2; c++)
            {
                int key = sortOrder[s][c];
                sortOrder[s][c] = sortOrder[s + 1][c];
                sortOrder[s + 1][c] = key;
            }
            if(s == 0) break;
            s--;
        }
    }

    return;
}

/*
 * Scala controlla se la carta successiva -1 è uguale a quella precedente
 * se cosi non è allora non è scala
 */
bool scala(char * manoAttuale[][2], int sortOrder[][2], int maxValore)
{
    for(int k = 0; k < 4; k++)
    {
        if(sortOrder[k][0] != (sortOrder[k+1][0] - 1) )
        {
            return false;
        }
    }

    return true;
}

bool poker(char * manoAttuale[][2], int sortOrder[][2], int maxValore)
{
    int carta_1 = sortOrder[0][0];
    int carta_2 = sortOrder[1][0];
    int carta_3 = sortOrder[2][0];
    int carta_4 = sortOrder[3][0];


    if(carta_1 == carta_2 && carta_2 == carta_3 && carta_3 == carta_4)
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

bool colore(char * manoAttuale[][2], int sortOrder[][2], int maxValore)
{
    int colore_1 = strcmp(manoAttuale[0][1], manoAttuale[1][1]);
    int colore_2 = strcmp(manoAttuale[1][1], manoAttuale[2][1]);
    int colore_3 = strcmp(manoAttuale[2][1], manoAttuale[3][1]);
    int colore_4 = strcmp(manoAttuale[3][1], manoAttuale[4][1]);

    if (colore_1 == 0) {
        return colore_1 && colore_2 == 0 && colore_3 == 0 && colore_4 == 0;
    }

    return false;
}

bool tris(char * manoAttuale[][2], int sortOrder[][2], int maxValore){

    int arr[5] = {sortOrder[0][0],sortOrder[1][0],
                  sortOrder[2][0],sortOrder[3][0],
                  sortOrder[4][0]};

    if(arr[0] == arr[1] && arr[1] == arr[2] && arr[3] != arr[4])
    {
        return true;
    }

    if(arr[1] == arr[2] && arr[2] == arr[3] && arr[4] != arr[0])
    {
        return true;
    }

    if(arr[2] == arr[3] && arr[3] == arr[4] && arr[0] != arr[1])
    {
        return true;
    }

    return false;
}

bool doppiaCoppia(char * manoAttuale[][2], int sortOrder[][2], int maxValore)
{
    int arr[5] = {sortOrder[0][0],sortOrder[1][0],
                  sortOrder[2][0],sortOrder[3][0],
                  sortOrder[4][0]};

    if(arr[0] != arr[1] && arr[0] != arr[2] && arr[1] == arr[2] && arr[3] == arr[4] && arr[1] != arr[4]){
        return true;
    }


    if(arr[0] == arr[1] && arr[1] != arr[2] && arr[2] != arr[3] && arr[3] == arr[4] && arr[4] != arr[0]){
        return true;
    }

    if(arr[0] == arr[1] && arr[2] == arr[3] && arr[4] != arr[0] && arr[4] != arr[2] && arr[2] != arr[1]){
        return true;
    }

    return false;
}


bool coppia(char * manoAttuale[][2], int sortOrder[][2], int maxValore)
{
    int arr[5] = {sortOrder[0][0],sortOrder[1][0],
                  sortOrder[2][0],sortOrder[3][0],
                  sortOrder[4][0]};

    for(int f = 0; f < 4; f++){
        for(int c = f + 1; c < 5; c++)
        {
            if(arr[f] == arr[c])
            {   
                return true;
            }
        }
    }
     
    return false;

    
}

