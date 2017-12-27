#include <stdio.h>
#include <stdlib.h>

#define SIZE 4


int main(int argc, char const *argv[]){

	int originalCode;
	int tableCodeEncrypted[SIZE];
	int table[][6] = { {1,2,5,7}, {3}, {4}, {6}, {8}, {9} };
	int decrypted[4];

	tableCodeEncrypted[0] = atoi(argv[1]);
	tableCodeEncrypted[1] = atoi(argv[2]);
	tableCodeEncrypted[2] = atoi(argv[3]);
	tableCodeEncrypted[3] = atoi(argv[4]);
	
	int cont;
	int xcont;
	int num;

	for(xcont = 0; xcont < 4; xcont++){
		for(cont = 0;cont < 4; cont++){
			num = tableCodeEncrypted[cont];
			switch(num){
				case 0: 
					decrypted[xcont] = table[0][cont];		
					printf("%d ", table[0][cont]);
					break;

				case 1:	
					decrypted[xcont] = table[1][0];		
					printf("%d ", table[1][0]);
					break;
				
				case 2:
					decrypted[xcont] = table[1][0];		
					printf("%d ", table[2][0]);
					break;

				case 4:
					decrypted[xcont] = table[0][0];		
					printf("%d ", table[3][0]);
					break;

				case 6:
					decrypted[xcont] = table[0][0];		
					printf("%d ", table[4][0]);
					break;

				case 7:
					decrypted[xcont] = table[0][0];		
					printf("%d ", table[5][0]);
					break;

				default:
	
					printf("Ok c'è qualcosa che non va\n");
	
			}
			
		
		}
		printf("\n");

	}

	return 0;
}


