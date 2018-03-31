/*
Problema delle 8 regine con approccio euristico
*/

#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N] = { {0} };
int asse_x[N] = { 0 };

/*
    
    

*/

bool isValid(int p_x, int p_y)
{
        
}

void p_board();

int main()
{
    // Posioni sull'asse
    int p_x;
    int p_y;
    
    p_x = 0;
    p_y = 0;
    
    board[p_x][p_y] = 1;
    
    p_board();
    
    
    return 0;
}

void p_board()
{
    puts("");
    
    int i,k;
    for(i = 0; i < N; i++)
    {
        for(k = 0; k < N; k++)
        {
            printf(board[i][k] == 0 ? "[ ]" : "[Q]");
        }
        puts("");
    }
        puts("");
        return;
}