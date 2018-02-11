#include <stdio.h>

int fattoriale(int n);

int main(){

	fattoriale(5);

	return 0;
}

int fattoriale(int n){
	static int tmp = n;
	if((n-1) != 0){
		printf("%3d\t x\t %d\t = \t%d\n",tmp, (n-1), (tmp * (n-1)));
	}

	tmp = (tmp * (n-1));

	return n<=1? n : n * fattoriale(n - 1);

}