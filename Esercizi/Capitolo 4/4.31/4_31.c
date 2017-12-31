#include <stdio.h>

int main(){

	
	int cnt;
	int xcnt;
	int max = 10;
	int scnt = max;
	int asterischi = 1;
	
	for(cnt = 1; cnt < max ;cnt++){
		for(scnt = max - cnt; scnt > 0; scnt--){
				printf(" ");
			}
		for(xcnt = 0; xcnt < asterischi; xcnt++){
			printf("*");
		}
		asterischi = asterischi + 2;
		printf("\n");

	}
	
	return 0;
}