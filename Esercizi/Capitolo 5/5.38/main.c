#include <stdio.h>

int fib(int);

int main(){

	printf("%d\n", fib(5));

	return 0;
}

int fib(int num){

	return (num <= 1) ? num : fib(num - 1) + fib(num - 2);

}