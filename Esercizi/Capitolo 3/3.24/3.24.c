
/**

trovare il numero maggiore tra 10 numeri

**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{	

	srand(time(NULL));

	int numeri[10];
	int sentinella = 0x0;



	for (int i = 0; i < 10 ; ++i)
	{
		numeri[i] = rand() % 20;
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10 - 1; ++j)
		{
			if(numeri[j] > numeri[j+1]){
				sentinella = numeri[j];
				numeri[j] = numeri[j+1];
				numeri[j+1] = sentinella;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", numeri[i]);
	}
	
	return 0;
}
