/*

Visualizzare ricorsivamente una stringa al contrario

*/

#include <stdio.h>
#include <stdlib.h>

void reverse(char *str, int dim);

int main()
{
    
    char nome[] = "Robert";
    int dim = sizeof(nome) / sizeof(*nome);
    reverse(nome, dim);
    
    return 0;
}

void reverse(char *str, int dim)
{
    if(dim == 0)
    {
        puts("\n");
        return;
    }
    
    printf("%c", str[dim - 1]);
    
    reverse(str, dim - 1);
    
    
}