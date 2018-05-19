//
// Created by Robert on 18/05/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//prototipi

void shuffle         (int [][13]);
void deal   (const int (*)[], const char * [], const char *[]);

int main()
{

    const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    const char *face[13] = {"Ace", "Deuce", "Three", "Four",
                            "Five", "Six", "Seven", "Eight",
                            "Nine", "Ten", "Jack", "Queen", "King"};

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

void deal(const int   wDeck[][13],
                   const char *wFace[],
                   const char *wSuit[] ){

    void mano(const int (*) [], const char * [], const char *[], int [][2]);

    int card;
    int row;
    int column;

    int r = 0;

    int arr[5][2];

    for(card = 1; card <= 52; card++)
    {
        for(row = 0; row <= 3; row++)
        {
            for(column = 0; column <= 12; column++)
            {
                if(wDeck[row][column] == card)
                {

                    if(r < 5){
                        arr[r][0] = row;
                        arr[r][1] = column;
                        r++;
                    }

                     printf("%5s of %-8s%c", wFace[column], wSuit[row],
                     card % 1 == 0 ? '\n' : '\t');

                }
            }
        }
    }


mano(wDeck, wFace, wSuit, arr);


    return;
}

void mano(const int   wDeck[][13],
                  const char *wFace[],
                  const char *wSuit[],
                  int arr[][2]){

    bool coppia         (const int (*) [], const char * [], const char *[], int [][2]);
    bool doppiaCoppia   (const int (*) [], const char * [], const char *[], int [][2]);
    bool tris           (const int (*) [], const char * [], const char *[], int [][2]);
    bool poker          (const int (*) [], const char * [], const char *[], int [][2]);
    bool colore         (const int (*) [], const char * [], const char *[], int [][2]);
    bool scala          (const int (*) [], const char * [], const char *[], int [][2]);


    bool (*check[6]) (const int   wDeck[][13],
                      const char *wFace[],
                      const char *wSuit[],
                      int arr[][2]) = {coppia, doppiaCoppia, tris, poker, colore, scala};

    system("cls");

    const char *mano[5][2];

    int x;

    for(x = 0; x < 5; x++)
    {
        mano[x][0] = wFace[arr[x][1]];
        mano[x][1] = wSuit[arr[x][0]];

        printf("%s %s \n",mano[x][0], mano[x][1]);
    }

        int ris = (*check[0]) ( wDeck, wFace, wSuit, arr);
        printf(ris ? "doppio" : "non doppio");


    return;

    }


bool coppia(const int   wDeck[][13],
            const char *wFace[],
            const char *wSuit[],
            int arr[][2]) {

    const char *aux[5] = {0};

    int cnt;
    for(cnt = 0; cnt < 5; cnt++)
    {
        aux[cnt] = wFace[arr[cnt][1]];
    }

    for(cnt = 1; cnt < 5; cnt++)
    {
        if (aux[0] == aux[cnt]) {
            return true;
        }
    }

    return false;

}

bool doppiaCoppia(const int   wDeck[][13],
                  const char *wFace[],
                  const char *wSuit[],
                  int arr[][2]) {

}

bool tris(const int   wDeck[][13],
          const char *wFace[],
          const char *wSuit[],
          int arr[][2]) {

}

bool poker(const int   wDeck[][13],
           const char *wFace[],
           const char *wSuit[],
           int arr[][2]) {

}

bool colore(const int   wDeck[][13],
            const char *wFace[],
            const char *wSuit[],
            int arr[][2]) {

}

bool scala(const int   wDeck[][13],
           const char *wFace[],
           const char *wSuit[],
           int arr[][2]) {

}








