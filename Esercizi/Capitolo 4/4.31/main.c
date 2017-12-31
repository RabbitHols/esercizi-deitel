#include <stdio.h>

int main(){

	
	int cnt;
	int xcnt;
	int max = 3;
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

	for(cnt = max; cnt > 0; cnt--){
		for(scnt = 0 + cnt; scnt < max; scnt++){
			printf(" ");
		}
		for(scnt = asterischi; scnt > 0; scnt--){
			printf("*");
		}
		printf("\n");
		asterischi = asterischi - 2;


	}

	
	return 0;
}