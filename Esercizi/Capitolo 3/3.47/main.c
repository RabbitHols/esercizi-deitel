/**
 a) Scrivere il fattoriale un un determinato numero dato in input
 b) Scrivere un programma che approssimi il valore della costante matematica "e"
 	tramite la seguente formula: e = 1 + 1/1! + 1/2! + 1/3!+ ecc...	
 c) Scrivere un programma che apporsismi il valore della costante matematice "e^x"
 	usando la formula e^x = 1 +  x^1 /1! + x^2 /2! + ecc ... 
 **/

#include <stdio.h>
#include <stdlib.h>

float fattoriale(float);
float approssimazione_e();
float approssimazione_x(float x);
float potenza(float num, float potenza);

int main(int argc, char const *argv[1]){

	if(argv[1] == '\0'){
		printf("Errore argomento richiesto\n");
		return 0;
	
	}

	float num = atof(argv[1]);
	
	printf("Il fattoriale di num è: %f \n", fattoriale(num));

	printf("L'approssimazione della costante è di: %f\n", approssimazione_e());

	printf("L'approssimazione della costante x è di: %f\n", approssimazione_x(num))	;

	return 0;
}

float fattoriale(float num){
	int cnt = num - 1;

	while(cnt != 0){
		num = cnt * num;
		cnt--;
	}

	return num;
}

float approssimazione_e(){

	float num = 1;
	
	int cnt = 1;

	while(cnt != 20){
		num = num + (1 / fattoriale(cnt) );
		cnt++;
	}


	
	return num;
}

float approssimazione_x(float x){
	float num = 1;
	float cnt = 1;

	while(cnt != 20){
		num  = num +  potenza(x,cnt) / fattoriale(cnt) ;
		cnt++;
	}
	

	return num;
		
}

float potenza(float num, float potenza ){
	int cnt = 1;
	float base = num;
	for(cnt; cnt < potenza; cnt++){
		num = num * base;
	}
	
	return num;
}
