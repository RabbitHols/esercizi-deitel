/*

Approccio euristico al salto del cavallo

*/
#include <stdio.h>
#include <stdbool.h>

#define N 8

bool isLegal(int x, int y);
int bestMove(int x, int y);
int lookUp(int x, int y);

void p_board();
void fillN();
void assignValue();
void resort(int moves[], int siz_1, int m_possibili[], int siz_2, int x, int y);
void insertSort(int moves[], int siz_1, int m_possibili[], int siz);

bool euristicMove(int x, int y, int stats);

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

static unsigned long long iterazioni = 0;

int board[N][N] = { {0} };

               
int main()
{
    
    int x = 0;
    int y = 0;

    p_board();
    assignValue();
    p_board();

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

/**
 Se ci sono due movimenti adicenti con lo stesso valore controlla quale
 sia il migliore da considerare
**/


bool euristicMove(int x, int y, int stats)
{
    
    if(stats == (N*N) + 10 )
    {
        return true;
    
    }
    
    iterazioni++; // Lo uso per contare la chiamata ricorsiva
    
    int p_x;
    int p_y;
    
    /*
    Moves salva la posizione delle mosse
    m_possibili usa moves per ricavare il valore della posizione
    */
    
    int moves[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; 
    int m_possibili[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    
    
    
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
Riordino l'array in modo da dare precedenza alle posizioni con meno movimenti.
L'algoritmo usato è un insert sort
*/
    
    insertSort(moves, 8, m_possibili, 8);

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
        
        if(m_possibili[c_r] == m_possibili[c_r + 1] && m_possibili[c_r] != -1)
        {
            int p_e = lookUp(p_x, p_y);
            
            
            int s_p_x = x + xMove[moves[c_r + 1]];
            int s_p_y = y + yMove[moves[c_r + 1]];
        
            int s_e = lookUp(s_p_x, s_p_y);
            
            if(p_e < s_e){
                int variabile_sentinella = moves[c_r];
                moves[c_r] = moves[c_r + 1];
                moves[c_r + 1] = variabile_sentinella;
            }
        }
        
        
        // In caso due valori uguali controllo quale sia il migliore da selezione
        
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
            if(board[i][j] > 9)
            {
                printf("[%02d]", board[i][j] - 10);
            }
            else 
            {
                printf("[%02d]", board[i][j]);
            }
        }
        puts("");
    }

    puts("");
    return;
    
}

void assignValue(){
    
    int mosse_valide = 0; // tengo il conto di quante mosse valide ci sono
    int p_x;
    int p_y;
    
    int i,k,r;
    for(i = 0; i < N; i++)
    {
        for(k = 0; k < N; k++)
        {
            
            // Controllo quante mosse valide ci siano
            mosse_valide = 0;
            for(r = 0; r < N; r++)
            {
                
                p_x = i + xMove[r];
                p_y = i + yMove[r];
                
                if(isLegal(p_x, p_y) == true )
                {
                    mosse_valide++;
                }
            }
            
            // Assegno il valore all'elemento nella scacchiera
            
            board[i][k] = mosse_valide;
            
        }
    }
    
    return;
}

int lookUp(int x, int y)
{
     
    int moves[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; 
    int m_possibili[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    
    resort(moves, 8, m_possibili,8,x, y);
    
    return m_possibili[0];
    
}

void resort(int moves[], int siz_1, int m_possibili[], int siz_2, int x, int y)
{
    
    int conta               = 0;
    int contMosseLegali     = 0;
    int p_x                 = 0;
    int p_y                 = 0;
    int contatore           = 0;
    
    for(contatore = 0; contatore < N; contatore++)
    {
        p_x = x + xMove[contatore];
        p_y = x + yMove[contatore];
        
        if(isLegal(p_x, p_y) == true )
        {
            moves[contMosseLegali] = contatore;
            m_possibili[contMosseLegali] = board[p_x][p_y]; // Assegno il numero di mosse possibili 
            contMosseLegali++;
        }
    }
    
    return;
    
}


/*
    Riordina l'array dal più piccolo al più grande e anche i movimenti 
    in base ai valori. L'algoritmo di riordinamente è: insert sort
*/
void insertSort(int moves[], int siz_1, int m_possibili[], int siz)
{
    
    int variabile_Temp;
    int rec;

    int contatore;  
    for(contatore = 0; contatore < N - 1; contatore++)
    {
        if(m_possibili[contatore] > m_possibili[contatore + 1])
        {
            rec = contatore + 1;
            while(rec != 0 && m_possibili[rec] < m_possibili[rec - 1])
            {
                variabile_Temp = m_possibili[rec];
                m_possibili[rec] = m_possibili[rec - 1];
                m_possibili[rec - 1] = variabile_Temp;
                
                variabile_Temp = moves[rec];
                moves[rec] = moves[rec - 1];
                moves[rec - 1] = variabile_Temp;
                       
                rec--;
             }
        }
    }
    
}