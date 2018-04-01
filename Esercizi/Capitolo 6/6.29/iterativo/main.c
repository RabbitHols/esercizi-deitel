#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define N 6

void fill(int board[][N], int siz);
void pboard(int board[][N], int siz);
bool isValid(int board[][N], int x, int y);
bool isCircolar(int board[][N], int x, int y);

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

int main()
{
  int board[N][N] = {0};
  int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
  int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

  int stack[N*N][4] = { {0} };
  
  
  int mov = 0;
  int x,px;
  int y,py;
  
  fill(board, N);  // riempio di -1
  
  x = 0;
  y = 0;
  
  board[x][y] = 0;
  
  int check;
  int k = 0; // Contatore
  while(mov != 35)
  {

    for(; k < 8; k++)
    {
      
      px = x + xMove[k];
      py = y + yMove[k];
      
      if(isValid(board, px, py) == true )
      {
        mov = mov + 1; // ora vale 1

        stack[mov][0] = k + 1;
        stack[mov][1] = x;
        stack[mov][2] = y;
        stack[mov][3] = check + 1;
        
        board[px][py] = mov;
        
        k = 0; // resetto il contatore
        
        x = px;
        y = py;
   
        break;
      }
      else
      {
        check++;
      }
      
      } // fine for
      
    if(mov == 35)
    {
     if(isCircolar(board, px, py) == false )
     {
        check = 8;
     }
     
    }
      
    
    if(check == 8)
    {
      board[x][y] = -1;
      
      k     = stack[mov][0];
      x     = stack[mov][1];
      y     = stack[mov][2];
      check = stack[mov][3];
    
      mov--;
      
    }
    else
    {
      check = 0;
    }
    

  } // fine while
  
  pboard(board, N);
     
  return 0;
}

bool isCircolar(int board[][N], int x, int y){

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

bool isValid(int board[][N], int x, int y)
{
  if(x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1)
  {
    return true;
  }
  return false;
}

void fill(int board[][N], int siz)
{
  int i, k;
  for(i = 0; i < N; i++)
  {
    for(k = 0; k < N; k++)
    {
      board[i][k] = -1;
    }
  }
}

void pboard(int board[][N], int siz)
{
  system("clear");
  int i, k;
  for(i = 0; i < N; i++)
  {
    for(k = 0; k < N; k++)
    {
      printf(board[i][k] == -1 ? "[  ]" : "[%2d]", board[i][k] );
    }
    puts("");
  }
}