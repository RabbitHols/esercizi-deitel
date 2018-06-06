/*
 * @Author: Robert Turturica 
 * @Date: 2018-05-22 21:41:14 
 * @Last Modified by:   Robert 
 * @Last Modified time: 2018-05-22 21:41:14 
 */

// Esercizio 7.13 Mano migliore

#include "header.h"

int main()
{
    srand(time(NULL));

    int mazzoCarte[52][2];
    char *manoGiocatore[NPLAYER][ROW][CLM];
    int sortOrder[NPLAYER][ROW][CLM];
    int combinazioneMaggiore[NPLAYER][2];

    int wins[2] = {0};

    shuffle();
    deal(mazzoCarte);
    giveCardsCoord(manoGiocatore, mazzoCarte);
    sortMani(manoGiocatore, sortOrder);
    controlloMano(manoGiocatore, sortOrder, combinazioneMaggiore);

    AI_Decision(mazzoCarte, 0, combinazioneMaggiore[0][0]);
    ManoGiocatore(manoGiocatore, sortOrder, 1);
    scartaCarta(mazzoCarte, 1);

    giveCardsCoord(manoGiocatore, mazzoCarte);
    sortMani(manoGiocatore, sortOrder);
    controlloMano(manoGiocatore, sortOrder, combinazioneMaggiore);

    mostraMani(manoGiocatore, sortOrder);
    vincitore(combinazioneMaggiore, sortOrder);
    cleaner(deck);

    return 0;
}
