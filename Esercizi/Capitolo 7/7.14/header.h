#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define IT 1000 // Iterazioni
#define NPLAYER 2
#define ROW 5
#define CLM 2

char *suit[4] = {"Di Cuori", "Di Denari", "Di Fiori", "Di Picche"};
char *face[13] = {"Asso", "Due", "Tre", "Quattro",
                  "Cinque", "Sei", "Seven", "Otto",
                  "Nove", "Dieci", "Regina", "Regina", "Re"};
int deck[4][13] = {0};

//prototipi

bool doppiaCoppia(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool poker(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool colore(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool tris(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool scala(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool coppia(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);
bool cartaAlta(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int);

void scambiaCarte(int[][2], int, int);
void AI_Decision(int [][2], int, int);

int cartaMaggiore(int[NPLAYER][ROW][CLM], int, int, int);

void shuffle();
void deal();
void giveCardsCoord(char * [NPLAYER][ROW][CLM], int[][CLM]);
void sortMani(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);
void controlloMano(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM], int [][2]);
void vincitore(int [][2],int [NPLAYER][ROW][CLM]);

void mostraMano(char * [NPLAYER][ROW][CLM], int[NPLAYER][ROW][CLM]);
void cleaner(int wDeck[][13]);

// Mescola carte
void shuffle()
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
        } while (deck[row][column] != 0);

        deck[row][column] = card;
    }
    return;
}

void deal(int mazzoCarte[][2])
{
    int card;
    int row;
    int column;

    int r = 0;
    // hand usato per catturare le prime carte in base a quanti giocatori vi sono

    for (card = 1; card <= 52; card++)
    {
        for (row = 0; row <= 3; row++)
        {
            for (column = 0; column <= 12; column++)
            {
                if (deck[row][column] == card)
                {
                    // Catturo i risultati nell'array
                    mazzoCarte[r][0] = row;
                    mazzoCarte[r][1] = column;
                    r++;
                }
            }
        }
    }

    return;
}

//  Assegno alla mano del giocatore le carte e le coordinate delle carte estratte dal mazzo.
void giveCardsCoord(char *manoGiocatore[NPLAYER][ROW][CLM], int mazzoCarte[][CLM])
{
    int carta = 0;

    for (int tab = 0; tab < NPLAYER; tab++)
    {
        for (int riga = 0; riga < ROW; riga++, carta++)
        {
            manoGiocatore[tab][riga][0] = face[mazzoCarte[carta][1]];
            manoGiocatore[tab][riga][1] = suit[mazzoCarte[carta][0]];
        }
    }
}

void controlloMano(char *manoGiocatore[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int combinazioneMaggiore[][2])
{

    bool (*check[7])(char *manoGiocatore[NPLAYER][ROW][CLM],
                     int sortOrder[NPLAYER][ROW][CLM],
                     int idPlayer) = {poker, colore, scala, tris, doppiaCoppia, coppia, cartaAlta};

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

    return;
}

void vincitore(int combinazioneMaggiore[][2],int sortOrder[NPLAYER][ROW][CLM]){
    
    int vincitore[1][2];
    
     /* 
    
    Qui va implementato il metodo che fa scegliere al giocatore x cosa fare se scartare o meno.,
    TODO: Qui va implementato il metodo che fa scegliere al giocatore x cosa fare se scartare o meno.,
    
     */

    //mostraMano(manoGiocatore, sortOrder);

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

        TODO: Per adesso mi manca da implementare colore e poker
    */

    
    vincitore[0][0] = combinazioneMaggiore[0][0];
    vincitore[0][1] = combinazioneMaggiore[0][1];

    for (int n = 1; n < NPLAYER; n++)
    {
        if (vincitore[0][0] > combinazioneMaggiore[n][0])
        {
            vincitore[0][0] = combinazioneMaggiore[n][0];
            vincitore[0][1] = combinazioneMaggiore[n][1];
            continue;
        }

        if (vincitore[0][0] == combinazioneMaggiore[n][0])
        {
            int winner = cartaMaggiore(sortOrder, vincitore[0][1], n, 0);
            if (winner == combinazioneMaggiore[n][1])
            {
                vincitore[0][0] = combinazioneMaggiore[n][0];
                vincitore[0][1] = combinazioneMaggiore[n][1];
            }
        }
    }

    printf("\nIl vincitore e' il giocatore nr %d\n\n", vincitore[0][1] + 1);

}

void scambiaCarte(int mazzoCarte[][2], int id, int from)
{

    for(int n = from, k = 51; n < 4; n++,k--)
    {
        for(int j = 0; j < 2; j++)
        {
            int tmp = mazzoCarte[n][j];
            mazzoCarte[n][j] = mazzoCarte[k][j];
            mazzoCarte[k][j] = tmp;
        }
    }
    
}

void AI_Decision(int mazzoCarte[][2], int idPlayer, int mano)
{

    switch (mano)
    {
    case 3:
        scambiaCarte(mazzoCarte, idPlayer, 3);
        break;
    case 4:
        scambiaCarte(mazzoCarte, idPlayer, 4);
        break;
    case 5:
        scambiaCarte(mazzoCarte, idPlayer, 2);
        break;
    case 6:
        scambiaCarte(mazzoCarte, idPlayer, 1);
        break;
    default:
        puts("error");
        break;
    }
}

int cartaMaggiore(int sortOrder[NPLAYER][ROW][CLM],
                  int idPlayer_1,
                  int idPlayer_2,
                  int cont)
{
    if (cont == 4)
    {
        return (sortOrder[idPlayer_1][cont][0] > sortOrder[idPlayer_2][cont][0]) ? idPlayer_1 : idPlayer_2;
    }

    if (sortOrder[idPlayer_1][cont][0] == sortOrder[idPlayer_2][cont][0])
    {
        return cartaMaggiore(sortOrder, idPlayer_1, idPlayer_2, cont + 1);
    }

    return (sortOrder[idPlayer_1][cont][0] > sortOrder[idPlayer_2][cont][0]) ? idPlayer_1 : idPlayer_2;
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

void sortMani(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM])
{
    for (int tab = 0; tab < NPLAYER; tab++)
    {
        for (int ncarte = 0; ncarte < ROW; ncarte++)
        {
            for (int x = 0; x < 13; x++)
            {
                if (strcmp(manoGiocatori[tab][ncarte][0], face[x]) == 0)
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

/* 
    Implementazione del pareggio per la scala, tecnicamente basta controllare chi ha la scala più alta, dunque ho
    dovuto reversare l'ordine per farlo funzionare con la funzione carta maggiore. 
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

    int tmp[1][2];

    for (int n = 0, k = 4; n < 5 / 2; n++, k--)
    {
        tmp[0][0] = sortOrder[idPlayer][n][0];
        sortOrder[idPlayer][n][0] = sortOrder[idPlayer][k][0];
        sortOrder[idPlayer][n][0] = tmp[0][0];

        tmp[0][1] = sortOrder[idPlayer][n][1];
        sortOrder[idPlayer][n][1] = sortOrder[idPlayer][k][1];
        sortOrder[idPlayer][n][1] = tmp[0][1];
    }

    return true;
}

bool poker(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
{
    int carta_1 = sortOrder[idPlayer][0][0];
    int carta_2 = sortOrder[idPlayer][1][0];
    int carta_3 = sortOrder[idPlayer][2][0];
    int carta_4 = sortOrder[idPlayer][3][0];
    int carta_5 = sortOrder[idPlayer][4][0];

    bool check = false;

    if (carta_1 == carta_2 && carta_2 == carta_3 && carta_3 == carta_4)
    {
        check = true;
    }

    if (carta_2 == carta_3 && carta_3 == carta_4 && carta_4 == carta_5)
    {
        check = true;
    }

    if (check == true)
    {
        if (carta_1 != carta_2)
        {
            int tmp[1][2];

            tmp[0][0] = sortOrder[idPlayer][0][0];
            sortOrder[idPlayer][0][0] = sortOrder[idPlayer][4][0];
            sortOrder[idPlayer][4][0] = tmp[0][0];

            tmp[0][1] = sortOrder[idPlayer][0][1];
            sortOrder[idPlayer][0][0] = sortOrder[idPlayer][4][1];
            sortOrder[idPlayer][4][1] = tmp[0][1];
        }

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

        int tmp[1][2];

        for (int n = 0, k = 4; n < 5 / 2; n++, k--)
        {
            tmp[0][0] = sortOrder[idPlayer][n][0];
            sortOrder[idPlayer][n][0] = sortOrder[idPlayer][k][0];
            sortOrder[idPlayer][n][0] = tmp[0][0];

            tmp[0][1] = sortOrder[idPlayer][n][1];
            sortOrder[idPlayer][n][1] = sortOrder[idPlayer][k][1];
            sortOrder[idPlayer][n][1] = tmp[0][1];
        }

        return true;
    }

    return false;
}

/* 
    Praticamente se trovo che nella mano vi è un tris swappo gli elementi manualmente mettendo i kicker in fondo in base
    al loro valore niente di complesso insomma

    FIXME: Da migliorare l'algoritmo e renderlo meno verboso

 */

bool tris(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
{

    bool check = false;
    int arr[5][2];
    int tmp[1][2];

    for (int n = 0; n < 5; n++)
    {
        arr[n][0] = sortOrder[idPlayer][n][0];
        arr[n][1] = sortOrder[idPlayer][n][1];
    }

    if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[3][0] != arr[4][0] && !check)
    {

        tmp[0][0] = arr[3][0];
        arr[3][0] = arr[4][0];
        arr[4][0] = tmp[0][0];

        tmp[0][1] = arr[3][1];
        arr[3][1] = arr[4][1];
        arr[4][1] = tmp[0][1];

        check = true;
    }

    if (arr[1][0] == arr[2][0] && arr[2][0] == arr[3][0] && arr[4][0] != arr[0][0] && !check)
    {

        tmp[0][0] = arr[0][0];
        arr[0][0] = arr[3][0];
        arr[3][0] = tmp[0][0];

        tmp[0][1] = arr[0][1];
        arr[0][1] = arr[3][1];
        arr[3][1] = tmp[0][1];

        tmp[0][0] = arr[3][0];
        arr[3][0] = arr[4][0];
        arr[4][0] = tmp[0][0];

        tmp[0][1] = arr[3][1];
        arr[3][1] = arr[4][1];
        arr[4][1] = tmp[0][1];

        check = true;
    }

    if (arr[2][0] == arr[3][0] && arr[3][0] == arr[4][0] && arr[0][0] != arr[1][0] && !check)
    {

        tmp[0][0] = arr[0][0];
        arr[0][0] = arr[4][0];
        arr[4][0] = tmp[0][0];

        tmp[0][1] = arr[0][1];
        arr[0][1] = arr[4][1];
        arr[4][1] = tmp[0][1];

        tmp[0][0] = arr[1][0];
        arr[1][0] = arr[3][0];
        arr[3][0] = tmp[0][0];

        tmp[0][1] = arr[1][1];
        arr[1][1] = arr[3][1];
        arr[3][1] = tmp[0][1];

        check = true;
    }

    if (check)
    {
        for (int n = 0; n < 5; n++)
        {
            sortOrder[idPlayer][n][0] = arr[n][0];
            sortOrder[idPlayer][n][1] = arr[n][1];
        }

        return true;
    }

    return false;
}

bool doppiaCoppia(char *manoGiocatori[NPLAYER][ROW][CLM], int sortOrder[NPLAYER][ROW][CLM], int idPlayer)
{

    /* 
    FIXME: Aggiustare assolutamente la logica dietro a doppia coppia, è orrenda davvero. Aggiustala.
    Comunque il funzionamento base è questo clono l'array per comodità poi controllo con delle if se il pattern della 
    doppia coppia ci sta nell'array una volta fatto cio mi trovo i due cloni li piazzo in cima e mi trovo il 4 elemento e lo 
    piazzo in fondo. Ho dovuto creare 2 array e fare infinito for veramente da ottimizzare fa schifo...

 */

    int arr[5][2];

    for (int n = 0; n < 5; n++)
    {
        arr[n][0] = sortOrder[idPlayer][n][0];
        arr[n][1] = sortOrder[idPlayer][n][1];
    }

    int check = 0;

    if (arr[0][0] != arr[1][0] && arr[0][0] != arr[2][0] && arr[1][0] == arr[2][0] && arr[3][0] == arr[4][0] && arr[1][0] != arr[4][0])
    {
        check = true;
    }

    if (arr[0][0] == arr[1][0] && arr[1][0] != arr[2][0] && arr[2][0] != arr[3][0] && arr[3][0] == arr[4][0] && arr[4][0] != arr[0][0])
    {
        check = true;
    }

    if (arr[0][0] == arr[1][0] && arr[2][0] == arr[3][0] && arr[4][0] != arr[0][0] && arr[4][0] != arr[2][0] && arr[2][0] != arr[1][0])
    {
        check = true;
    }

    if (check)
    {
        int tmp_1 = 0;
        int tmp_2 = 0;
        int tmp_3 = 0;
        int tmp_4 = 0;

        int n = 0;
        while (check)
        {
            for (int k = n + 1; k < 5; k++)
            {
                if (arr[n][0] == arr[k][0])
                {
                    tmp_1 = n;
                    tmp_2 = k;
                    check = 0;
                }
            }
            n++;
        }

        check = 1;
        while (check)
        {
            for (int k = n + 1; k < 5; k++)
            {
                if (arr[n][0] == arr[k][0] && arr[n][0] != arr[tmp_1][0])
                {
                    tmp_3 = n;
                    tmp_4 = k;
                    check = 0;
                }
            }
            n++;
        }

        int sir[5][2] = {0};

        sir[0][0] = arr[tmp_4][0];
        sir[0][1] = arr[tmp_4][1];
        sir[1][0] = arr[tmp_3][0];
        sir[1][1] = arr[tmp_3][1];
        sir[2][0] = arr[tmp_2][0];
        sir[2][1] = arr[tmp_2][1];
        sir[3][0] = arr[tmp_1][0];
        sir[3][1] = arr[tmp_1][1];

        int f;
        for (int n = 0; n < 5; n++)
        {
            if (arr[n][0] != arr[tmp_1][0] && arr[n][0] != arr[tmp_3][0])
            {
                sir[4][0] = arr[n][0];
                sir[4][1] = arr[n][1];
            }
        }

        for (int n = 0; n < 5; n++)
        {
            sortOrder[idPlayer][n][0] = sir[n][0];
            sortOrder[idPlayer][n][1] = sir[n][1];
        }

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

                int arr[5][2] = {-1};

                arr[0][0] = sortOrder[idPlayer][f][0];
                arr[0][1] = sortOrder[idPlayer][f][1];

                arr[1][0] = sortOrder[idPlayer][c][0];
                arr[1][1] = sortOrder[idPlayer][c][1];

                for (int n = 2, k = 0; n < 5; n++, k++)
                {
                    if (sortOrder[idPlayer][k][0] == arr[0][0])
                    {
                        k++;
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

                for (int n = 0; n < ROW; n++)
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
    while (n != 2)
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

void cleaner(int wDeck[][13])
{
    for (int n = 0; n < 4; n++)
    {
        for (int k = 0; k < 13; k++)
        {
            wDeck[n][k] = 0;
        }
    }
}