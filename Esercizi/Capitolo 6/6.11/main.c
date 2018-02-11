/*

Bubble sort:

a) Dopo il primo passaggio, il numero più grande sarà stato sicuramente sistemato
nell'elemento con l'indice più alto del vettore, dopo il secondo passaggio i due
numeri più grandi saranno "a  posto" e cosi via. Invece di eseguire nove confronti 
a ogni passaggio, modificate l'ordinamento a bolle cosi che ne esegua solo otto 
nel secondo e sette nel terzo e cosi via.

b) I dati nel vettore potrebbero già essere nell'ordine appropriato o in uno 
vicino a questo, perciò perchè eseguire nove passaggi quando ne potrebbero
bastare meno? modificate l'ordinamento a bolle, in modo da verificare se alla 
fine di ogni passaggio siano stati eseguiti degli scambi. Nel caso che non siano
stati eseguiti, allora i dati saranno già nell'ordine giusto, perciò il programma
dovrà terminare la propria esecuzione.

*/

#include <stdio.h>

void bsort(int [], size_t );
void psort(int [], size_t);

int main(int argc, char const *argv[]){
	
	int arr[] 	= {9,2,4,1,6,8,3};
	int siz 	= sizeof(arr) / sizeof(*arr);

	puts("Prima di essere riordinato\n");
	psort(arr, siz);

	bsort(arr, siz);

	puts("Dopo esser stato riordinato\n");
	psort(arr, siz);

	puts("Test ordinazione su uno già ordinato\n");
	bsort(arr, siz);
	psort(arr, siz);

	

	return 0;
}

void bsort(int arr[], size_t siz){
	
	int move = 0;	
	int swap;
	int siz_2 = siz - 1;
	int check = 0;

	for(int cnt_1 = 0; cnt_1 < siz; cnt_1++){
		for(int cnt_2 = 0; cnt_2 < siz_2; cnt_2++){
			move++;
			if(arr[cnt_2] > arr[cnt_2 + 1]){
				swap = arr[cnt_2];
				arr[cnt_2] = arr[cnt_2 + 1];
				arr[cnt_2 + 1] = swap;
				check = 1;
			}
		}
		siz_2 = siz_2 - 1;
		if(check == 0){
			printf("Numero mosse :%d\n\n", move);
			return;
		}
	}

	printf("Numero mosse :%d\n\n", move);
}

void psort(int arr[], size_t siz){

	for(int cnt = 0; cnt < siz; cnt++){
		printf("| %d |", arr[cnt]);
	}
	puts("\n");


}