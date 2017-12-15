#include <stdio.h>

void determinatore_PD(int num){
num = (num & 1) ? printf("DISPARI") : printf("PARI");
}

int main(int argc, char const *argv[])
{

	int num = 4;
	determinatore_PD(num); 
	
	return 0;
}