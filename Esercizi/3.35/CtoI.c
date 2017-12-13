#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

int buff = strlen(argv[1]); // Grandezza di argv
char n[buff + 1];

strcpy(n, argv[1]);

//char n[] = "235";
int t[sizeof(n) - 1];
int base = 1;
int conv = 0;
int numero_Finale = 0x0;

for(int i = sizeof(n) - 2, cont = 0; i >= 0; i--, cont++){

// printf("%c\n", n[i]);
	
//	printf("VAL :%c\n", n[i]);
	conv = n[i] - '0';
//	printf("%d\n", conv);	
	t[cont] = conv  * base;
 	base *= 10;
	
}


for(int i = 0; i < sizeof(t) / 4; i++){

	numero_Finale += t[i];

}

printf("NUMERO FINALE: %d", numero_Finale); 


return 0;
}


