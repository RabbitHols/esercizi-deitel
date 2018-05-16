/**
 * Figura 7.26
**/

#include <stdio.h>
#define SIZE 10

/* Prototipo */

void Bsort( int work[], const int size, int (*compare) (int a, int b) );

int ascending(int a, int b);
int descending(int a, int b);

int main(){
	int order; 	//sceglie l'ordine dell'ordinamento
	int cnt;
	int a[SIZE] = {2,6,4,8,10,12,89.68,45,37};

	printf("1 ascendetente\n 2 Discendente");
	scanf(" %d", &order);
	printf("\nOrdine originale dell'array");

	// Visualizza il vettore originale

	for(cnt = 0; cnt < SIZE; cnt++)
	{
		printf("%5d", a[cnt]);
	}

	if(order == 1)
	{
		Bsort(a, SIZE, ascending);
		printf("\nData items in ascending order\n");
	}
	else
	{
		Bsort(a,SIZE, descending);
		printf("\nData items in descending order\n");
	}

	//Visualizza il vettore ordinato
	for(cnt = 0; cnt < SIZE; cnt++)
	{
		printf("%5d", a[cnt]);
	}

	printf("\n");

	return 0;

}

void
Bsort(int work[], const int size, int (*compare) (int a, int b) )
{
	int pass;	//Contatore dei passaggi
	int count;  //Contatore dei confronti

	void swap(int *element1Ptr, int *element2Ptr); // Prototipo

	for(pass = 1; pass < size; pass++)
	{
		for(count = 0; count < size - 1; count++)
		{
			//Scambia gli elementi
			if( (*compare) (work[count], work[count + 1] ) )
			{
				swap(&work[count], &work[count + 1]);
			}
		}
	}

	return;
}

void 
swap(int *element1Ptr, int *element2Ptr)
{
	int hold;

	hold 		 = *element1Ptr;
	*element1Ptr =*element2Ptr;
	*element2Ptr = hold;
}

int 
ascending(int a, int b)
{
	return b < a;
}

int 
descending(int a, int b)
{
	return b > a;
}

