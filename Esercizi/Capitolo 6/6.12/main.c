/*

Scrivete delle istruzioni singole che svolgano le seguenti operazioni sui vettori
unidimensionali:

1)Azzerare i 10 elementi del vettore di interi counts
2)aggiungete a 1 a ognuno dei 15 elementi contenuti nel vettori di interi bonus
3)Leggete dalla tastiera i 12 valori in virgola mobile del vettori monthlytemps
4)Visualizzate in colonna i 5 valori contenuti nel vettore di interi bestScores

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void psort(int arr[], size_t siz);
void vsort(int arr[], size_t siz);
void zsort(int arr[], size_t siz);
void qsort(int arr[], size_t siz);
void lsort(int arr[], size_t siz);
void flush(int n);

int main(int argc, char const *argv[])
{
	
	int counts[15];
	size_t dim_counts = sizeof(counts) / sizeof(*counts);

	vsort(counts, dim_counts);
	psort(counts, dim_counts);
	zsort(counts, dim_counts);
	psort(counts, dim_counts);

	puts("\n\n");

	int bonus[15];
	size_t dim_bonus = sizeof(counts) / sizeof(*counts);

	vsort(bonus, dim_bonus);
	psort(bonus, dim_bonus);
	qsort(bonus, dim_bonus);
	psort(bonus, dim_bonus);

	
	puts("\n\n");

	int mth[12];
	size_t dim_mth = sizeof(mth) / sizeof(*mth);

	lsort(mth, dim_mth);
	psort(mth, dim_mth);

	puts("\n\n");

	int besc[5];
	size_t dim_besc = sizeof(besc) / sizeof(*besc);

	vsort(besc, dim_besc);
	psort(besc, dim_besc);


	return 0;
}

void lsort(int arr[], size_t siz){
	if(siz < 12){
		return;
	}
	for(int cnt = 0; cnt < 12; cnt++){
		puts("Dammi valore\n");
		scanf("%d", &arr[cnt]);
		flush(arr[cnt]);
	}
}

void flush(int c){
	while(c != '\n' && getchar() != '\n');

}
void psort(int arr[], size_t siz){

	for(int cnt = 0; cnt < siz; cnt++){
		printf("| %d |", arr[cnt]);
	}

}

void vsort(int arr[], size_t siz){
	for(int i = 0; i < siz; i++){
		arr[i] = rand() % 10;
	}
}

void zsort(int arr[], size_t siz){
	if(siz < 10){
		return;
	}

	for(int cnt = 0; cnt < 10; cnt++){
		arr[cnt] = 0;
	}

}

void qsort(int arr[], size_t siz){
	if(siz < 15){
		return;
	}
	for(int cnt = 0; cnt < 15; cnt++){
		arr[cnt] += 1;
	}
}
