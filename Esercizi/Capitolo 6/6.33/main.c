/*
    
Palindromo - Ricorsione: 
    Scrivere una funzione ricorsiva che ritorni true se la stringa di caratteri è
    palindroma e false in caso non lo sia. La funzione deve ingnorare gli spazi
    e la punteggiatura.

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(char *stringa, int dimensione);
bool control(char *stringa);

int main(void)
{
    
    char stringa[] = "iààoi";
    int dimensione = strlen(stringa);
    
    printf( control(stringa) ? "PALINDROMA" : "NON PALINDROMA" );
    puts("");
    
    return 0;
}

bool control(char *stringa)
{
    char *str = (char *) calloc (strlen(stringa), sizeof(char));
    
    int c2  = 0;
    int cnt = 0;
    for(cnt = 0; cnt < strlen(stringa); cnt++)
    {
        if(stringa[cnt] >= 'a' && stringa[cnt] <= 'z')
        {
            str[c2] = stringa[cnt];
            c2++;
        }
    }
    
    str[c2] = '\0';
    str = (char *) realloc(str, c2 + 1);
    
    
    printf("\nPRIMA : %s\n", stringa);
    printf("DOPO : %s\n", str);

    return isPalindrome(str, c2);
    
    
}

bool isPalindrome(char *stringa, int dimensione)
{
    if(dimensione < 2 )
    {
        return true;
    }
  
    if(stringa[0] == stringa[dimensione - 1]){
        isPalindrome(stringa + 1, dimensione - 2);
    }
    else
    {
        return false;
    }
    
}