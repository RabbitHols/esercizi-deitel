/*

8 Regine iterativo

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define N 8

void pBoard(int arr[][N], int dim);

bool iSafe(int arr[][N], int queen[], int siz, int x, int y);


int main()
{
    
    int board[N][N] = { {0} };
    int queen[N]    = {0};
    
    bool lookup = false;
    
    int contatore   = 0;
    int count_q     = 0;
    
    
    pBoard(board, N);
    
    while(count_q != 8)
    {
        pBoard(board, N);
        sleep(0);
        system("clear");
        
        for(; contatore <= N; contatore++)
        {
            if( iSafe(board, queen, N, contatore, count_q) && contatore < N )
            {
                board[count_q][contatore] = 1;
                queen[count_q] = contatore;
                count_q++;
                contatore = 0;
                break;
            } else if(contatore >= N)
            {
                lookup = true; 
                break;
            }
                
        }
    
        if(lookup == true)
        {       
                board[count_q - 1][queen[count_q - 1]] = 0;
                contatore = queen[count_q - 1] + 1;
                count_q = count_q - 1;
                lookup = false;
                
        }
        
    }
    
    
    pBoard(board, N);
    
    return 0;
}

bool iSafe(int arr[][N], int queen[], int siz, int x, int y)
{
    
    int contatore = y - 1;
    for(; contatore >= 0; contatore--)
    {
        bool isDiagonal = abs(x - queen[contatore]) == abs(y - contatore);
        if(x == queen[contatore] || isDiagonal == true )
        {
            return false;
        }
    }
    
    return true;
    
}

void pBoard(int arr[][N], int dim)
{
    int x,y;
    for(x = 0; x < N; x++)
    {
        for(y = 0; y < N; y++)
        {
            printf( arr[x][y] ? "[Q]" : "[ ]" );
        }
        puts("");
    }
      
    return;
}