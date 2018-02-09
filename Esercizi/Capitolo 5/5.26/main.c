/*
 * Vedere se un numero è perfetto
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(int num);

int main(){

	for(size_t cnt = 1; cnt < 10000000; cnt++){
		if(check(cnt) != -1){
		
			printf("%lu\n", check(cnt));
		}	
	}

 return 0;
}

int check(int num){
	
	int resto;
	int perfetto = 0;
	for(int i = 1; i <= (num - 1); i++){
	
	resto = num % i;
	perfetto = (resto == 0)? perfetto + i : perfetto;

	}

	return (num == perfetto)? perfetto : -1;
}
