#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (a,b) ( ((a) > (b))? a:b  )

void bubblesort(int *array, int size);

int main(int argc, char const *argv[]){
	
	srand(time(NULL));

	int dimensione = 20;
	int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int iterazioni = 1000;

	for(int loop = 0; loop < 10; loop++){

		
	for(int i = 0; i < iterazioni; i++){
		int num = rand() % dimensione;

		arr[num] = arr[num] + 1;
	}

	bubblesort(arr, dimensione);


	}
	

	return 0;
}

void bubblesort(int *array, int size){
	
	int temp;
	int maggiore = array[0];
	
	
	for(int t = 0; t < size; t++){
		if(array[t] > array[t+1]){
			maggiore = t;
		} 
	}

	for(int cnt_1 = 0; cnt_1 < size; cnt_1++){
		for(int cnt_2 = 0; cnt_2 < size - 1; cnt_2++){
			if(array[cnt_2] > array[cnt_2 + 1]){
				temp = array[cnt_2];
				array[cnt_2] = array[cnt_2 + 1];
				array[cnt_2 + 1] = temp;
			}
		}
	}

	printf("\nNUMERO MAGGIORE = %d con %d\n",maggiore, array[size-1]);


}
