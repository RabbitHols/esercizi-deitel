/**

Scrivere un programma che visualizzi una scatole, un ovale, una freccia e un diamante


****	**		* 		*
*  *   *  *    ***     * * 
*  *   *  *     *     *   *  
****    **      *      * *
                        * 

**/

#include <stdio.h>

void disegna_Figure(){
	printf(" ****   **    *     *\n ");
	printf("*  *  *  *  ***   * *\n");
	printf(" *  *  *  *   *   *   *\n");
	printf(" ****   **    *    * * \n");
	printf("				   *   \n");
}	


int main(int argc, char const *argv[])
{

	disegna_Figure();
	return 0;
}