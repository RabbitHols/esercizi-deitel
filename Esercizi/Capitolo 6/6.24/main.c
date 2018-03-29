/*

Approccio euristico al salto del cavallo

*/
#include <stdio.h>
#include <stdbool.h>

#define N 8

bool isLegal(int x, int y);
int bestMove(int x, int y);

void p_board();
void fillN();
bool euristicMove(int x, int y, int stats);

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

static unsigned long long iterazioni = 0;

int board[N][N] = { {2,3,4,4,4,4,3,2},
                    {3,4,6,6,6,6,4,3},
                    {4,6,8,8,8,8,6,4},
                    {4,6,8,8,8,8,6,4},
                    {4,6,8,8,8,8,6,4},
                    {4,6,8,8,8,8,6,4},
                    {3,4,6,6,6,6,4,3},
                    {2,3,4,4,4,4,3,2}        
                 };
                 
int main()
{
    
    int x = 0;
    int y = 0;
    
    
    board[x][y] = 10;
    if(euristicMove(x,y, 11) == true)
    {
        p_board();
    }
    else 
    {
        puts("\n risultato inesistente spiacente \n");
    }
    
    printf("\nITERAZIONI COMPIUTE:  %llu\n ", iterazioni);
    
   
    
    return 0;
}


bool euristicMove(int x, int y, int stats)
{
    iterazioni++; // Lo uso per contare le volte che la funzione
    
    int p_x;
    int p_y;
    
    /*
    Moves salva la posizione delle mosse
    m_possibili usa moves per ricavare il valore della posizione
    */
    
    int moves[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; 
    int m_possibili[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    
    
    if(stats == (N*N) + 10 )
    {
        return true;
    
    }
    
    
    /*Sceglie le mosse valide*/
    
    int cnt;
    int s_c = 0;// secondo contatore
    for(cnt = 0; cnt < 8; cnt++)
    {
        p_x = x + xMove[cnt];
        p_y = y + yMove[cnt];
        
        if(isLegal(p_x, p_y) == true ){
            moves[s_c] = cnt;
            m_possibili[s_c] = board[p_x][p_y]; // valore della mossa
            s_c++;
        }
    }
    
    /*
        Riordina l'array dal più piccolo al più grande e anche i movimenti 
        in base ai valori. L'algoritmo di riordinamente è un semplice bubble sort
    */

    int c_1, c_2; // Contatori
    for(c_1 = 0; c_1 < N; c_1++){
        for(c_2 = 0; c_2 < N - 1; c_2++)
        {
            if(m_possibili[c_2] > m_possibili[c_2 + 1])
            {
                /* Riordino dal valore più piccolo */
                int temp;
                temp = m_possibili[c_2];
                m_possibili[c_2] = m_possibili[c_2 + 1];
                m_possibili[c_2 + 1] = temp;
                
                /* Il tutto viene riflesso anche sui movimenti*/
                
                temp = moves[c_2];
                moves[c_2] = moves[c_2 + 1];
                moves[c_2 + 1] = temp;
                
            }
        }
    }


    // Da qui in poi richiamo la funzione in modo ricorsivo e uso il backtracking
    
    int last_value; // Il valore della posizione va salvato
    int c_r;
    for(c_r = 0; c_r < N; c_r++)
    {
        if(m_possibili[c_r] == -1)
        {
            continue;
        }
        
        p_x = x + xMove[moves[c_r]];
        p_y = y + yMove[moves[c_r]];
       
        last_value = board[p_x][p_y];
        board[p_x][p_y] = stats;
        
        if(euristicMove(p_x, p_y, stats + 1) == true){
            return true;
        }
        else
        {
            board[p_x][p_y] = last_value;
        } 
        
    }
    
    return false;
    
}

bool isLegal(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && board[x][y] < 10)
    {
        return true;
    }
    
    return false;
}

void p_board()
{
    puts("");
    
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {   
            printf("[%02d]", board[i][j] - 10 );
        }
        puts("");
    }

    puts("");
    return;
    
}
