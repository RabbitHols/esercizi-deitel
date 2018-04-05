#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define N 6

void fill_Array     (int board[][N]);
void print_Array    (int board[][N]);

bool isValid        (int board[][N], int * x, int * y);
bool isCircolar     (int board[][N], int * x, int * y);

int main(void)
{
    int board[N][N];

    int xMove[] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    
}