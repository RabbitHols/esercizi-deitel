/*
Approccio brutale delle 8 regine
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

int board[N][N] = {{0}};
int queen[N] = {0};

void f_r();
void p_r();
int autoMove();

bool iSafe(int c_q, int clm);

/*

[Q][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][Q][ ][ ][ ][ ][ ]
[Q][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][ ][ ]

*/


int main()
{
    int val = 0;
    board[0][val] = 1;
    queen[0] = val; 
    
    autoMove(1);

    p_r();
   
    
    return 0;
}

int autoMove(int c_q)
{
    
    if(c_q == 8)
    {
        return true;
    }
    // c_q = 1
    int cnt;
    for(cnt = 0; cnt < N; cnt++)
    {
        queen[c_q] = cnt;
        if(iSafe(c_q, cnt) == true )
        {
            board[c_q][cnt] = 1;
            if(autoMove(c_q + 1) == true)
            {
                return true;
            }
            else 
            {
                board[c_q][cnt] = 0;
            }
        }
    }
    
    return false;
}

bool iSafe(int c_q, int clm)
{
    
    int cnt;
    for(cnt = 0; cnt < c_q; cnt++)
    {
        if( clm == queen[cnt] || abs(clm - queen[cnt]) == abs(c_q - cnt) ){
            break;
        }
        
        if(cnt == c_q - 1)
        {
            return true;
        }
        
    }
    
    return false;
    
}

void f_r()
{
    int k,j;
    for(k = 0; k < N; k++)
    {
        for(j = 0; k < N; j++)
        {
            board[k][j] = 0x0;
        }
    }    
}

void p_r()
{
    
    puts("");
    int k,j;
    for(k = 0; k < N; k++)
    {
        for(j = 0; j < N; j++)
        {
            printf( board[k][j] ? "[Q]" : "[ ]" );
        }
        puts("");
    }
    puts("");
}
