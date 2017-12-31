/**
 * Visualizzare una tabella che mostri il valore di PGreco
 * 4 - 4/3 + 4/5
 **/

#include <stdio.h>

int main(){

	float PiGreco = 4;
	float Denominatore = 3;
	for(int cnt = 0; cnt < 1000000; cnt++){
		if(cnt % 2 != 0){
			PiGreco = PiGreco + (4/Denominatore);
		} else {
			PiGreco = PiGreco - (4/Denominatore);
		}
		Denominatore = Denominatore + 2;
	}

	printf("%f\n", PiGreco);

	return 0;
}