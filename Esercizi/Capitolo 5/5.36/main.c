#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{	
	
	int num = num = 1 + rand() % 1001;
	int check;
	int tentativi = 1;
	
	do{

		if(tentativi > 10){
			printf("Spiacente troppi tentativi !\n");
			break;
		}

		puts("Prova a indovinare il numero\n");
		scanf("%d", &check);

		if(check == num){puts("Complimenti hai vinto");}
		if(check < num){ puts("Troppo piccolo ritenta");} 
		if(check > num){ puts("Troppo grande ritenta");}
		tentativi++;

	} while(check != num);

	if(tentativi == 10){puts("Giusto in tempo\n");}
	if(tentativi < 10){puts("La sai lunga");}

	return 0;
}