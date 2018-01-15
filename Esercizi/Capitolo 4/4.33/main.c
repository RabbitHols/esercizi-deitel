/** Scrivere i numeri Romani a da 1 a 100

I 1
V 5
X 10
L 50
C 100
D 500	
M 1000




 **/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int num = atoi(argv[1]);
	int cnt = 0;

	while(num != 0){
		if(num >= 1000){
			num = num - 1000;
			cnt++;
			printf("M");

		} else if(num >= 500){
			num = num - 500;
			cnt++;
			printf("D");
		} else if(num >= 100){
			num = num - 100;
			cnt++;
			printf("C");
		} else if(num >= 50){
			num = num - 50;
			cnt++;
			printf("L");
		} else if(num >= 10){
			num = num - 10;
			cnt++;
			printf("X");
		} else if(num >= 5){
			num = num - 5;
			cnt++;
			printf("V");
		} else {
			num = num - 1;
			cnt++;
			printf("I");
		}
	}


	return 0;
}