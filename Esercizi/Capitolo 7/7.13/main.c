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

    char *suit[4] = {"Di Cuori", "Di Denari", "Di Fiori", "Di Picche"};
    char *face[13] = {"Asso", "Due", "Tre", "Quattro",
                      "Cinque", "Sei", "Seven", "Otto",
                      "Nove", "Dieci", "Regina", "Regina", "Re"};

    int deck[4][13] = {0};

    shuffle(deck);
    deal(deck, face, suit);

    return 0;

}
