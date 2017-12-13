/**

calcolare quadrato e cubo

**/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 11 ++i)
	{	printf("%d \t", i );
		printf("%d \t ",i * i);
		printf("%d \t\n", i * i * i);
	}

	return 0;
}