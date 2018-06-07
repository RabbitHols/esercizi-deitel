#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

void mossa(int *, int *);
void display(int[][2], int *, int *);

typedef int tartaruga;
typedef int lepre;

int main(int argc, char const *argv[])
{

    int percorso[70][2] = {0};

    srand(time(NULL));

    int StatoTartaruga = 0;
    int StatoLepre = 0;

    int *trt = &StatoTartaruga;
    int *lpr = &StatoLepre;

    bool check = true;

    puts("BANG !!");
    puts("AND THEY'RE OF !!!");

    while (check)
    {
        Sleep(1000);
        system("cls");
        mossa(trt, lpr);
        display(percorso, trt, lpr);
        if (*trt >= 70)
        {
            puts("TORTOISE WINS !!! YAY !!!");
            check = false;
        }
        if (*lpr >= 70)
        {
            puts("Hare wins. Yuch");
            check = false;
        }
    }

    return 0;
}

void display(int percorso[][2], int *trt, int *lpr)
{
    puts("");

    for (int n = 0; n < 2; n++)
    {
        for (int k = 0; k < 70; k++)
        {
            if (k != 0 && k == *lpr && k == *trt)
            {
                printf("[OUTCH !]");
                continue;
            }
            if (n == 0)
            {
                printf(k == *trt ? "[T]" : "[ ]");
            }
            if (n == 1)
            {
                printf(k == *lpr ? "[L]" : "[ ]");
            }
        }
        printf("\n");
    }
}

void mossa(int *trt, int *lpr)
{

    tartaruga arrampicataRapida = +3;
    tartaruga Scivolone = -6;
    tartaruga ArrancataLenta = +1;

    lepre Dormita = +0;
    lepre SaltoLungo = +9;
    lepre ScivoloneLunego = -12;
    lepre SaltoCorto = +1;
    lepre ScivoloneCorto = -2;

    int dado = 1 + rand() % 10;

    switch (dado)
    {
    case 1:
        *trt += arrampicataRapida;
        *lpr += Dormita;
        break;
    case 2:
        *trt += arrampicataRapida;
        *lpr += Dormita;
        break;
    case 3:
        *trt += arrampicataRapida;
        *lpr += SaltoLungo;
        break;
    case 4:
        *trt += arrampicataRapida;
        *lpr += SaltoLungo;
        break;
    case 5:
        *trt += arrampicataRapida;
        *lpr += ScivoloneLunego;
        break;
    case 6:
        *trt += Scivolone;
        *lpr += SaltoCorto;
        break;
    case 7:
        *trt += Scivolone;
        *lpr += SaltoCorto;
        break;
    case 8:
        *trt += ArrancataLenta;
        *lpr += SaltoCorto;
        break;
    case 9:
        *trt += ArrancataLenta;
        *lpr += ScivoloneCorto;
        break;
    case 10:
        *trt += ArrancataLenta;
        *lpr += ScivoloneCorto;
        break;
    default:
        puts("Errore");
    }

    if (*trt < 0)
    {
        *trt = 0;
    }
    if (*lpr < 0)
    {
        *lpr = 0;
    }
}