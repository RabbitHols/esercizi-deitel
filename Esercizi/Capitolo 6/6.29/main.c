/*

Salto del cavallo ciclico.
La 64esima mossa deve distare 1 mossa dalla prima mossa

*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define N 6

void fill_Board();
void print_Board();

bool isLegal(int x, int y);
bool isCircolar(int x, int y);
bool automove(int x, int y, int num_mossa);

int board[N][N]     = { {0} };

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };


int main()
{
    int x;
    int y;

    fill_Board();
    
    x = 0;
    y = 0;
    
    board[x][y] = 0;
    
    if(automove(x,y,1) == true){
        print_Board();
        puts("risolto");
    }
    else
    {
        puts("non risolto");
    }
    
    
    return 0;
}

bool automove(int x, int y, int num_mossa)
{
    
    
    int px;
    int py;
    int rx;
    int ry;

    if(num_mossa == N*N)
    {
       if(isCircolar(x,y) == true){
           return true;
       }
       return false;
    }

    int i;
    for(i = 0; i < N; i++)
    {
        px = x + xMove[i];
        py = y + yMove[i];
        
        
        if(isLegal(px, py) == true)
        {
            
            board[px][py] = num_mossa;
            if(automove(px, py, num_mossa + 1) == true)
            {
                return true;
            }
            
            else 
            {
             board[px][py] = -1;   
            }
        }
    }
    
    return false;
    
}

bool isCircolar(int x, int y){

    int p_x;
    int p_y;
    
    int k = 0;
    for(k = 0; k < 8; k++){
        
        p_x = x + xMove[k];
        p_y = y + yMove[k];
        
        if(p_x == 0 && p_y == 0)
        {
            return true;
        }
    }
    
    return false;
}

bool isLegal(int x, int y)
{
    
    if(x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1)
    {
        return true;
    }
    
    return false;
}

void fill_Board()
{
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            board[i][j] = -1;
        }
    }
    
    return;
}

void print_Board()
{
    system("clear");
    puts("");
    
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf( board[i][j] == -1 ? "[  ]" : "[%2d]", board[i][j] );
        }
        puts("");
    }
    puts("");
    
    return;
}