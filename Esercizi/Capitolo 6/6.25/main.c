/*
Approccio brutale del salto del cavallo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
int board[N][N] = {{0}};

unsigned long long static cycles = 0;

/*Intestazioni funzioni*/
void fillArray      ();
void printBoard     ();

bool isLegal        (int x, int y);

int  autoMove       (int x, int y, int moveK);

int main()
{
    int pos_x;
    int pos_y;
    int moveK;
    
    fillArray();
    
    /*Si parte dalla posizione 0, movek traccia il numero della mossa*/
    board[0][0]     = 0; 
    pos_x           = 0;
    pos_y           = 0;
    moveK           = 1;
    
    /*Mi scorro tutte le mosse possibili*/
    
    autoMove(pos_x, pos_y, moveK);
    printBoard();
    return 0;
}

int autoMove(int x, int y, int moveK)
{
    cycles = cycles + 1;
    
    int n_x;
    int n_y;
    
    if(moveK == N*N)
    {
        return true;
    }
    
    /*Provo tutte le possibili combinazioni delle mosse */
    
    int k;
    for(k = 0; k < N; k++)
    {
        n_x = x + xMove[k];
        n_y = y + yMove[k];
        
        if( isLegal(n_x, n_y) )
        {
            board[n_x][n_y] = moveK;
            if( autoMove(n_x, n_y, moveK + 1) == true )
            {
                return true;
            }
            else
            {
                board[n_x][n_y] = -1; // Backtracking
            }        
        } 
    }
    
    return false;
}

bool isLegal(int x, int y)
{
    return ( x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1) ? true : false;
}

void printBoard()
{
    system("clear");
    puts("\n");
    
    int x;
    int y;
    for(x = 0; x < N; x++)
    {
        for(y = 0; y < N; y++)
        {
            printf(board[x][y] == -1 ? "[  ]" : "[%02d]", board[x][y]);
        }
        puts("");
    }
    
    printf("\nNUMERO DI CICLI ESEGUITI: %llu\n", cycles);
    
    puts("\n");
    
    return;
}

void fillArray()
{
    int x;
    int y;
    for(x = 0; x < N; x++)
    {
        for(y = 0; y < N; y++)
        {
            board[x][y] = -1;
        }
    }
}

