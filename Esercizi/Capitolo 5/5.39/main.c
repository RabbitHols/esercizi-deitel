#include <stdio.h>

void torre_hanoi(int, char, char, char);

int main(int argc, char const *argv[])
{
	char a = 'A';
	char b = 'B';
	char c = 'C';

	torre_hanoi(3, a,b,c);

	return 0;
}

void torre_hanoi(int num, char PALO_1, char PALO_2, char PALO_3){

	if(num == 1){
		printf("Da %c -> %c\n", PALO_1, PALO_3);
		return;
	}

	torre_hanoi(num - 1, PALO_1, PALO_3, PALO_2);
	printf("Da %c -> %c\n", PALO_1, PALO_3);
	torre_hanoi(num - 1, PALO_2, PALO_1, PALO_3);
}

