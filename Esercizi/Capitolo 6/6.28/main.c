/*
    Scrivere un programma che produca 20 numeri casuali da 1 a 20. Il programma deve
    immagazzinare in un vettore tutti i valori non duplicati. Utilizzate il vettore
    più piccolo possibile per portare a termine questo lavoro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 20

int main()
{
    srand(time(NULL));
    
    int vettore[N]          = {0};
    int vect[N]             = {0};
    int num_Casuale; 
    
    /*
    [1,3,4,1               ]
    */
    
    int shift = 0;
    int i;
    for(i = 0; i < N; i++)
    {
        num_Casuale = 1 + rand() % 20;
        vect[i] = num_Casuale;
        
        
        bool isEqual = false;
        int k = i;
        for(k = i; k >= 0; k--)
        {
            if(num_Casuale == vettore[k])
            {
                isEqual = true;
                ++shift;
            }
        }
        
        if(isEqual != true)
        {
            vettore[i - shift] = num_Casuale;
        }
        
    }
    
    /*
    Stampa vettori
    */
    
    puts("Vettore con duplicati e non");
    for(i = 0; i < N; i++)
    {
        printf(" %d", vect[i]);
    }
    puts("\n");
    for(i = 0; i < N; i++)
    {
        printf(" %d", vettore[i]);
    }
    puts("\n");
    
    
    
    return 0;
}