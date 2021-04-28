#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define WIDTH 9
#define HEIGHT 9

void gravity(int M[HEIGHT][WIDTH], bool* modif, int i, int j, int numite)
{
    if (M[i][j]==10 || M[i][j]==0){
            return 0;
    }
    else if (M[i+1][j] < M[i][j])                           //Test puis effectue si possible le déplacement vers le bas
    {
        char temp = M[i+1][j];
        M[i+1][j] = M[i][j];
        M[i][j] = temp;
        *modif = true;
    }
    else if (M[i+1][j+numite] < M[i][j])                    //Test puis effectue si possible le déplacement en diagonale
    {
        char temp = M[i+1][j+numite];
        M[i+1][j+numite] = M[i][j];
        M[i][j] = temp;
        *modif = true;
    }
    else if (M[i+1][j-numite] < M[i][j])                    //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
    {
        char temp = M[i+1][j-numite];
        M[i+1][j-numite] = M[i][j];
        M[i][j] = temp;
        *modif = true;
    }
    else if (M[i][j+numite] < M[i][j])                      //Test puis effectue si possible le déplacement vers le côté
    {
        char temp = M[i][j+numite];
        M[i][j+numite] = M[i][j];
        M[i][j] = temp;
        *modif = true;
    }
    else if (M[i][j-numite] < M[i][j])                      //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    {
        char temp = M[i][j-numite];
        M[i][j-numite] = M[i][j];
        M[i][j] = temp;
        *modif = true;
    }
    return 0;
}


void change(int M[HEIGHT][WIDTH], int numite, int length, bool* modif)
{
    for (int i = HEIGHT-1; i>=0; i--)
    {
        for (int j =  WIDTH-1; j>=0; j--)
        {
            gravity(M, modif, i, j, numite);
        }
    }
}

int matrice(void){
    int M[HEIGHT][WIDTH]
    for (int i=0; i<HEIGHT;i++)
    {
        M[i][0]=10;
        M[i][HEIGHT-1]=10;
    }
    for (int j=0;j<WIDTH;j++)
    {
        M[0][j]=10;
        M[WIDTH-1]=10;
    }
    for (int p=1;p<HEIGHT-1;p++)
    {
        for (int q=1;q<WIDTH-1;p++)
            M[p][q]=0;
    }
    return M;
}

