/**
 * Scrivete delle istruzioni che assegnigno alla variabil n degli interi casuali compresi nei seguenti intervalli:
 * 1 <= n <= 2
 * 1 <= n <= 100
 * 0 <= n <= 9
 * 1000 <= n <= 1112
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizzatore(int, int);

int main(){
	
	srand(time(NULL));
		
	int min[] = {1,1,0,1000};
	int max[] = {2,100,9,1112};


	for(int i = 0; i < 4; i++){
		randomizzatore(min[i], max[i]);
	}

	
	return 0;
}

void randomizzatore(int min, int max){
	printf("%li\n", ( min + rand()%max ));
}
