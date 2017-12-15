/**

L'interesse semplice su un mutuo è calcolato dalla formula 

interest = principal * rate * days / 365

La forumula precendete presume che:
rate 		= tasso
principale 	= capitale

**/

#include <stdio.h>

int main(int argc, char const *argv[])
{

	int ANNO		= 365;

	int giorni		= 0x0;
	float tasso 	= 0x0;
	float capitale	= 0x0;
	float interesse = 0x0;

	capitale	= 1000;
	tasso 		= 2;
	giorni		= 365;

	interesse = capitale * tasso * (float)giorni / (float)ANNO;

	printf("%.2f\n", interesse);


	return 0;
}