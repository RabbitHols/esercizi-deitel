/* 
Ottimizzare l'algoritmo di merscolamento
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//prototipi

void shuffle(int[][13]);
void deal(int (*)[], char *[], char *[]);
void startNumbers(int[][13]);
void newShuffle(int[][13]);
void Newdeal(int (*)[], char *[], char *[]);

int main()
{

    char *suit[4] = {"Di Cuori", "Di Denari", "Di Fiori", "Di Picche"};

    char *face[13] = {"Asso", "Due", "Tre", "Quattro",
                      "Cinque", "Sei", "Sette", "Otto",
                      "Nove", "Dieci", "Regina", "Regina", "Re"};

    int deck[4][13] = {0};

    srand(time(NULL));

    startNumbers(deck);
    newShuffle(deck);
    Newdeal(deck, face, suit);

    /* 
    shuffle(deck);
    deal(deck, face, suit);
  */
    return 0;
}

void Newdeal(int wDeck[][13],
             char *wFace[],
             char *wSuit[])
{

    int card;
    int row;
    int column;

    bool check = false;

    int iterazioni = 0;

    for (card = 1; card <= 52; card++)
    {

        for (row = 0; row <= 3; row++)
        {
            for (column = 0; column <= 12; column++)
            {

                iterazioni++;

                if (wDeck[row][column] == card)
                {
                    printf("%s of %s\n", wFace[column], wSuit[row]);
                    check = true;
                    break;
                }
            }
            if (check)
            {
                check = false;
                break;
            }
        }
    }

    printf("\n --> %d\n", iterazioni);

    return;
}

void newShuffle(int deck[][13])
{
    for (int n = 0; n < 4; n++)
    {
        for (int k = 0; k < 13; k++)
        {
            int row = rand() % 4;
            int clm = rand() % 13;

            int tmp = deck[n][k];
            deck[n][k] = deck[row][clm];
            deck[row][clm] = tmp;
        }
    }
}

void startNumbers(int deck[][13])
{
    int cnt = 1;
    for (int n = 0; n < 4; n++)
    {
        for (int k = 0; k < 13; k++, cnt++)
        {
            deck[n][k] = cnt;
        }
    }
}

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

    int iterazioni = 0;

    for (card = 1; card <= 52; card++)
    {
        for (row = 0; row <= 3; row++)
        {
            for (column = 0; column <= 12; column++)
            {

                iterazioni++;

                if (wDeck[row][column] == card)
                {
                    printf("%s of %s\n", wFace[column], wSuit[row]);
                }
            }
        }
    }

    system("cls");
    printf("\n --> %d\n", iterazioni);

    return;
}
