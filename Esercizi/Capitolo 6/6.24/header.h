#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define N N

/* Movimenti validi */
int move_x[N] = {-2,-1,+1,+2,+2,+1,-1,-2};
int move_y[N] = {+1,+2,+2,+1,-1,-2,-2,-1};

/*Intestazioni*/

void reflush();
void printBoard(int arr[][N], int siz);
void muoviCavallo(int arr[][N], int siz, int *pos_x, int *pos_y );

bool controllaMovimento(int arr[][N], int siz, int *pos_x, int *pos_y, int movimentoDaEseguire);

/* Muove il cavallo automaticamente */


/* Muove il cavallo sulla scacchiera*/

void muoviCavallo(int arr[][N], int siz, int *pos_x, int *pos_y )
{
    int movimentoDaEseguire;
    
    int cnt;
    for(cnt = 0; cnt < 10; cnt++)
    {   
        printBoard(arr, siz);
        printf("Attualmente ti trovi in pos %d %d\n", *pos_x, *pos_y);        
                
                
        puts("In quale direzione vuoi muovere il cavallo ?");
        puts("0 : NORD/EST");
        puts("1 : EST/NORD");
        puts("2 : SUD/EST");
        puts("3 : EST/SUD");
        puts("4 : SUD/OVEST");
        puts("5 : OVEST/SUD");
        puts("6 : OVEST/NORD");
        puts("7 : NORD/OVEST");
        printf("\n SCEGLI :");
            scanf("%d", &movimentoDaEseguire);
            reflush();
        puts("\n");
        
        if(controllaMovimento(arr, siz, pos_x, pos_y, movimentoDaEseguire))
        {
            arr[*pos_x][*pos_y] = 1;      
        } else {
            printf("Mossa non valida\n");
            sleep(1);
        } 
        
        
    } /*Fine ciclo for*/
        
}
    
/* Stampa la scacchiera su schermo*/

void printBoard(int arr[][N], int siz)
{
    system("clear");
    puts("\n");
    int riga, colonna;
    for(riga = 0; riga < siz; riga++)
    {
        for(colonna = 0; colonna < siz; colonna++)
        {
            printf( (arr[riga][colonna] == 0 ) ? "[ ]"  : "[C]");
        }
        puts("");
    }
}

/* Controlla se è il movimento da eseguire è valido */

bool controllaMovimento(int arr[][N], int siz, int *pos_x, int *pos_y, int movimentoDaEseguire)
{
      int asse_x = *pos_x + (move_x[movimentoDaEseguire]);
      int asse_y = *pos_y + (move_y[movimentoDaEseguire]);
      
      if(asse_x > 0 && asse_x < N && asse_y > 0 && asse_y < N && arr[asse_x][asse_y] == 0)
      {
          *pos_x = asse_x;
          *pos_y = asse_y;
          return true;
      }
      
      return false;
}

void reflush()
{
    int ogg;
    while( (ogg = getchar() )!= '\n' && ogg != EOF);
}