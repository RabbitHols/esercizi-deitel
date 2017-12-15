/**
 * Visualizzare una tabella che mostri il valore di PGreco
 * 4 + 4/3 + 4/5
 **/

#include <stdio.h>

void pGreco();

int main(){

	pGreco();

	return 0;
} 

void pGreco(){

	int i = 0x0;

	float p = 4;
	float x = 3;

	for(i = 0; i <= 10000000; i++){	
	
		if(i % 2 == 0){	p = p - (4/x);  }

		else {	p = p + (4/x);  }

		x += 2;
	}

	printf("%float", p);

}
