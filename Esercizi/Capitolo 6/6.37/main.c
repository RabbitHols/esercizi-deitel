/*

Funzione ricorsiva che stampa un array ricorsivamente

*/

#include <stdio.h>

void lookup(int arr[], int dim);

int main()
{
    
    int arr[] = {1,2,3,4,5};
    int dim = sizeof(arr) / sizeof(*arr);
    
    lookup(arr, dim);
    
    return 0;
}

void lookup(int arr[], int dim)
{
    if(dim == 0)
    {
        puts("");
        return; 
    }
    
    printf("%d", arr[0]);
    lookup(arr + 1, dim - 1);
}