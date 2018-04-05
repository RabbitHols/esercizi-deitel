/*

Trovare il valore minimo in un vettore ricorsivamente

*/

#include <stdio.h>

int min(int arr[], int dim);

int main()
{
    int arr[] = {11,9,5,2,3,10};
    int siz = sizeof(arr) / sizeof(*arr);
    
    printf("%d\n", min(arr, siz));    
    
    return 0;
}

int min(int arr[], int dim)
{
    
    if(dim == 1)
    {
        return arr[0];
    }
    
    int minore = arr[0];
    
    minore = minore < min(arr + 1, dim - 1) ? minore : min(arr + 1, dim - 1);
    
    return minore;
    
}