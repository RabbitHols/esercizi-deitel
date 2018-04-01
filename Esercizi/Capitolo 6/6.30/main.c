/*
    Creare un array e in base agli indici assegnare 1 o 0.
    1 -> Se l'indice è primo
    0 -> Se non è primo
    
    Per fare ciò usate il crivello di eratostene
*/

#include <stdio.h>
#include <stdbool.h>

void fill(int arr[], int siz);
void pboard(int arr[], int siz);

int main()
{
    
    int arr[1000];
    int siz = sizeof(arr) / sizeof(*arr);
    
    fill(arr, siz);
    
    arr[1] = 0;
    
    int i;
    int k;
    for(i = 2; i < siz; i++)
    {
        while(arr[i] != 1)
        {
            i++;
        }
        
        for(k = i + 1; k < siz; k++)
        {
            if(arr[k] == 1){
                arr[k] = (k % i == 0) ? 0 : 1;
            }
        }
    }
    
    pboard(arr, siz);
        
    return 0;
}

void fill(int arr[], int siz)
{
    int i;
    for(i = 0; i < siz; i++){
        arr[i] = true;
    }
}


void pboard(int arr[], int siz)
{
    int i;
    for(i = 0; i < siz; i++){
        printf("%d ", i);
        printf( (arr[i] == 1) ? "PRIMO \n" : "NON PRIMO \n" );
    }
}