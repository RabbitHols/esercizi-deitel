/*

Leggete in input 20 numeri, ognuno dei quali comprso tra 10 e 100 estremi
inclusi. Ogni volta che leggete un numero visualizzatelo qualoria non sia un
duplicato di uno già letto. Preparatevi al "caso peggiore" in cui tutti
e 20 i numeri differenti. Utilizzate il vettore più piccolo possibile per
risolvere questo problema

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

void vlist(int arr[], size_t siz);
void plist(int arr[], size_t siz);
void alist(int arr[], size_t siz);
int main(int argc, char const *argv[]){
	
	int arr[DIM] = {0};

	vlist(arr, DIM);
	plist(arr, DIM);

	puts("\n\n");

	alist(arr, DIM);

	return 0;
}

void vlist(int arr[], size_t siz){
	for(int cnt = 0; cnt < siz; cnt++){
		arr[cnt] = 10 + rand() % 100;
	}
}

void plist(int arr[], size_t siz){
	for(int cnt = 0; cnt < siz; cnt++){
		printf("| %d |", arr[cnt]);
	}
}

void alist(int arr[], size_t siz){

	int check = 0;
	printf("| %d |", arr[0]);
	for(int cnt = 1; cnt < siz; cnt++){
		for(int cnx = cnt; cnx > 0; cnx--){
			if(arr[cnt] == arr[cnx - 1]){
				check = 1;
			}
		}
		if(check == 1){
			check = 0;
			continue;
		}
		printf("| %d |", arr[cnt]);
	}
}