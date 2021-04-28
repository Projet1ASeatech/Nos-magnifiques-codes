#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 9

void gravity(int M[SIZE][SIZE], bool* modif, int i, int j, int numite)
{
    if (M[i][j]==10 || M[i][j]==0){
            return 0;
    }
    else if (M[i+1][j] < M[i][j])                           //Test puis effectue si possible le déplacement vers le bas
    {
        char temp = M[i+1][j];
        M[i+1][j] = M[i][j];
        M[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (M[i+1][j+numite] < M[i][j])                    //Test puis effectue si possible le déplacement en diagonale
    {
        char temp = M[i+1][j+numite];
        M[i+1][j+numite] = M[i][j];
        M[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (M[i+1][j-numite] < M[i][j])                    //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
    {
        char temp = M[i+1][j-numite];
        M[i+1][j-numite] = M[i][j];
        M[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (M[i][j+numite] < M[i][j])                      //Test puis effectue si possible le déplacement vers le côté
    {
        char temp = M[i][j+numite];
        M[i][j+numite] = M[i][j];
        M[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (M[i][j-numite] < M[i][j])                      //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    {
        char temp = M[i][j-numite];
        M[i][j-numite] = M[i][j];
        M[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    return 0;
}


void change(int M[SIZE][SIZE], int numite, int length, bool* modif)
{
    for (int i = 8; i>=0; i--)
    {
        for (int j = 8; j>=0; j--)
        {
            gravity(M, modif, i, j, numite);
        }
    }
    printf("modif=%d\n",*modif);
}
