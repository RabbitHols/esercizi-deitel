/*
Modificate il programma della figura 6.16 in modo che il programma sia 
in grado di gestire un pareggio per il valore della moda. Verificate che 
la funzione anche la funzione median, in modo che sia calcolata la media
dei due elementi di mezzo, in un vettore che contenga un numero pari di 
elementi.

media: 	sappiamo cosa sia
mediana: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 99

void psort(int arr[], size_t siz); // stampa array
void bsort(int arr[], size_t siz); // bubble sort migliorato
void popola(int arr[], size_t siz); // popola l'array con i dati

float f_media(int arr[], size_t siz);
void f_moda(int arr[], size_t siz);
int f_mediana(int arr[], size_t siz);

int main(int argc, char const *argv[]){
	
	srand(time(NULL));	


	int arr[DIM];

	popola(arr, DIM);

	puts("L'array popolato è il seguente: \n");
	psort(arr,DIM);

	float media = f_media(arr, DIM);
	printf("La media dell'array e' di: %f", media);

	puts("\n\n");

	f_moda(arr, DIM);

	puts("\n\n");

	int mediana = f_mediana(arr, DIM);
	printf("La mediana e' di: %d", mediana);
	puts("\n");



	return 0;
}

int f_mediana(int arr[], size_t siz){
	if(siz % 2 != 0){
		return arr[siz / 2];
	}
		int num_1 = arr[siz / 2];
		int num_2 = arr[(siz / 2) - 1];
		int risultato = (num_1 + num_2) / 2;
		return risultato;
	
}

void f_moda(int arr[], size_t siz){

	int moda[10] = {0};
	int max = -1;
	int valori_modali[10] = {0};
	int cont = 0;

	for(int cnt = 0; cnt < siz; cnt++){
		++moda[arr[cnt]];
	}

	for(int l = 0; l < 10; l++){
		max = (max > moda[l])? max : moda[l];
	}

	for(int cnt_2 = 0; cnt_2 < 10; cnt_2++){

		if(max == moda[cnt_2]){
			++valori_modali[cnt_2];
			cont += 1;
		}
	}

	printf("La moda e': %d\n", max);
	printf("Abbiamo ben %d valori modali\n\n", cont);

	for(int co = 0; co < 10; co++){
		if(valori_modali[co] != 0){
			printf("| %d |", co);
		}
	}

	puts("\n");

	bsort(moda, 9);

	printf("Che si ripetono ben: %d", moda[9]);


}

float f_media(int arr[], size_t siz){
	unsigned int media = 0;

	for(int cnt = 0; cnt < siz; cnt++){
		media += arr[cnt];
	}

	return (float)(media / 99);
}

void popola(int arr[], size_t siz){	
	for(int cnt = 0; cnt < siz; cnt++){
		arr[cnt] = 1 + rand() % 9;
	}
}


void bsort(int arr[], size_t siz){
	int sent;
	int siz2 = siz - 1;
	int check = 0;

	for(int cnt = 0; cnt < siz; cnt++){
		for(int cnt_2; cnt_2 < siz2; cnt_2++){
			if(arr[cnt_2] > arr[cnt_2 + 1]){
				sent = arr[cnt_2];
				arr[cnt_2] = arr[cnt_2 + 1];
				arr[cnt_2 + 1] = sent;
				check = 1;
			}
		}
	}
}

void psort(int arr[], size_t siz){
	for(int cnt = 0; cnt < siz; cnt++){
		printf("| %d |", arr[cnt]);
	}

	puts("\n\n");
}
