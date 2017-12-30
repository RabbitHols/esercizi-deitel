/**
Scrivere un programma che visualizzi ciò

*      ***   ***    *
**     ** 	  **   **	
***	   *	   *  ***

**/

#include <stdio.h>

int main(){

	int cnt;
	int xcnt;
	int tabs;
	int zcnt; 
	int ytabs;
	int ycnt;

	printf("\n");
	for(cnt = 1; cnt < 10; cnt++){
		for(xcnt = 1; xcnt < cnt + 1; xcnt++){
			printf("*");
		}
		for(tabs = cnt; tabs < 10; tabs++){
				printf(" ");
		}
		for(zcnt = 10; zcnt > cnt; zcnt--){
				printf("*");
		}
		for(ytabs = 0; ytabs < cnt + cnt; ytabs++){
				printf(" ");
		}
		for(zcnt = 10; zcnt > cnt; zcnt--){
				printf("*");
		}
		for(tabs = cnt; tabs < 10; tabs++){
				printf(" ");
		}
		for(xcnt = 1; xcnt < cnt + 1; xcnt++){
			printf("*");
		}
		printf("\n");
	}
		
	return 0;
}