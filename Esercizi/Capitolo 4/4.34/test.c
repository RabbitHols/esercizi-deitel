#include <stdio.h>

int main(){

	int arr[5] = {1,0};
	
	int cnt = 2;
	
	for(int cont = cnt - 1; cont >= 0; cont--){
		printf("%d", *(arr+cont) );
	}
	
	

	
	return 0;
}
