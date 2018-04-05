/*
Ricerca lineare tramite ricorsione
*/

#include <stdio.h>
#include <stdbool.h>

bool lookup(int arr[], int dim, int find);

int main()
{
    int tofind = 0;
    int arr[] = {1,42,6,2,3};
    int siz = sizeof(arr) / sizeof(*arr);
    
    puts("");
    printf( lookup(arr, siz, tofind) ? "TROVATO" : "NON TROVATO" );
    puts("");
    
    
    return 0;
}

bool lookup(int arr[], int dim, int find)
{
    if(dim == 1){ return false; };
    return (arr[0] == find) ? true : lookup(arr + 1, dim - 1, find);
}