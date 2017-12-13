/**
 * Scrivi in forma binaria un numero e trasformalo in decimale:
 * ex: 00110 = 4
 */

#include <stdio.h>
#include <math.h>

int main(){

int n = 111101;	

int resto;
int decimanle = 0;
int i = 0;

while(n != 0){
	resto = n % 10; // 1101 % 10 --> 1
	n /= 10; 	// 1101 / 10 --> 110
	decimanle = decimanle + resto * pow(2,i); // 0 = 0 + 1 * 2^0
	i++;
}

printf("%d\n", decimanle);

return 0;
}
 
