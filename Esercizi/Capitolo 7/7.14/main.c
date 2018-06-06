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

    for (int n = 0, iterazioni = 100; n < iterazioni; n++)
    {
        shuffle();
        deal(mazzoCarte);
        giveCardsCoord(manoGiocatore, mazzoCarte);
        sortMani(manoGiocatore, sortOrder);
        controlloMano(manoGiocatore, sortOrder, combinazioneMaggiore);
        mostraMano(manoGiocatore, sortOrder);

        if (AI_Decision(mazzoCarte, 0, combinazioneMaggiore[0][0]) == true)
        {
            giveCardsCoord(manoGiocatore, mazzoCarte);
            sortMani(manoGiocatore, sortOrder);
            controlloMano(manoGiocatore, sortOrder, combinazioneMaggiore);
            mostraMano(manoGiocatore, sortOrder);
        }

        switch (vincitore(combinazioneMaggiore, sortOrder))
        {
        case 1:
            wins[0] = wins[0] + 1;
            break;

        case 2:
            wins[1] = wins[1] + 1;
            break;

        default:
            puts("Error");
            break;
        }

        cleaner(deck);
    }

    system("cls");

    printf("Il giocatore 1 ha vinto %d volte\n", wins[0]);
    printf("Il giocatore 2 ha vinto %d volte ", wins[1]);

    return 0;
}
