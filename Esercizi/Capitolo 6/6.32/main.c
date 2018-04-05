/*

Ordinamento per selezione - Ricorsivo:
    Ricerca in un array l'elemento più piccolo, quando sarà stato trovato
    metterlo in prima posizione. Farlo finquando non sarà rimasto un solo 
    elemento disponibile da ordinare.

*/

#include <stdio.h>
#include <stdbool.h>

void sort(int arr[], int indice);


int main(void)
{
    
    int arr[]   = {4,2,10,9,1};
    int dim     = sizeof(arr) / sizeof(*arr);
    
    puts("ARRAY NON ORDINATO");
    int k;
    for(k = 0; k < dim; k++)
    {
        printf("%2d ", arr[k]);
    }
    
    
    sort(arr, dim);
    
    puts("");
    puts("ARRAY ORDINATO");
    
    for(k = 0; k < dim; k++)
    {
        printf("%2d ", arr[k]);
    } 
    
    puts(""); 
    
    return 0;
}

void sort(int arr[], int indice)
{
    if(indice == 1)
    {
        return;
    }
    
    int k;
    for(k = 0; k < indice; k++)
    {
        if(arr[0] > arr[k])
        {
            int temp;
            temp = arr[k];
            arr[k] = arr[0];
            arr[0] = temp;
        }
    }

    sort(arr + 1, indice - 1);
    
    return;
}
