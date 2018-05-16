#include <stdio.h>

int main()
{
    
    char * libri[] = {"Zio tommaso", "Dio cane", "Canarino il piccino"};
    char fantasia[] = {*libri[0]};
    
    printf("%s", fantasia[0]);
    
    return 0x0;
    
    
}