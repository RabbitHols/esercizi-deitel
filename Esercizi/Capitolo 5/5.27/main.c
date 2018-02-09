/**
 * Una funzioen che che determini se un numero sia primo o meno
 * Stampare i primi 1000 numeri primi
 * Spiegare perchè radice quadrata è meglio di n/2
 **/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int primos(int);

int main(int argc, char const *argv[]){

	//int num = atoi(argv[1]);

	for(int cnt = 0; cnt <= 1000; cnt++){

		if(primos(cnt) == 1){
		printf("%d\n", cnt);
		}if(primos(cnt) == 0) {
		printf("NON PRIMO\n");
		}if(primos(cnt) == -1){
		printf("1 non viene contato\n");
		}
	
	}

return 0;
}

int primos(int num){
	
	if(num == 2 || num == 3){
		return 1;
	}if(num % 2 == 0){
		return 0;
	}if(num == 1){
		return -1;
	}	

	for(int cnt = 2; cnt < (num / 2); cnt++){
		if(num % cnt == 0 && cnt != num){
		return 0;
		}
	}

	return 1;

}

// Sbagliato la verifica va fatto anche sugli pseudo primi (Fermant non basta)

int primo(int num){

	// n^p - n = x e x % 2 = 0 true
	
	return ( ((int)pow(2,num) - 2) % num == 0 )? 1 : 0;
	 
}
