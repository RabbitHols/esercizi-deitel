/*
Può il main essere richimato in maniera ricorsiva?
*/

#include<stdio.h>
int main()
{
    static int i=1;  // *
    printf("%d\n",i++);
    if(i==6)
    {
        return 0;
    }
    main(); // recursive call of main() 
}