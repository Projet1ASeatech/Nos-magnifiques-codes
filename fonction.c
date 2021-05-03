#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define WIDTH 20
#define HEIGHT 28

/* ##################################### */
/* ###       Fonction gravity        ### */
/* ### Gère le déplacement des cases ### */
/* ##################################### */
void gravity(int M[HEIGHT][WIDTH], bool* modif, int i, int j, int numite)
{
    if (M[i][j]==10 || M[i][j]==0){
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
}

/* ################################################ */
/* ###              Fonction change             ### */
/* ### Parcours la matrice pour appeler gravity ### */
/* ################################################ */
void change(int M[HEIGHT][WIDTH], int numite, bool* modif)
{
    for (int i = HEIGHT-1; i>=0; i--)
    {
        for (int j =  WIDTH-1; j>=0; j--)
        {
            gravity(M, modif, i, j, numite);
        }
    }
}

/* ################################### */
/* ###       Fonction matrice      ### */
/* ###    Génère la matrice vide   ### */
/* ################################### */
void matrice(int M[HEIGHT][WIDTH]){
    for (int i=0; i<HEIGHT;i++)
    {
        M[i][0]=10;
        M[i][HEIGHT-1]=10;
    }
    for (int j=0;j<WIDTH;j++)
    {
        M[0][j]=10;
        M[WIDTH-1][j]=10;
    }
    for (int p=1;p<HEIGHT-1;p++)
    {
        for (int q=1;q<WIDTH-1;q++)
            M[p][q]=0;
    }
}

void add_water(int M[HEIGHT][WIDTH], int x, int y, int cote, int index){
	int i = (x-x%cote)/cote;
	int j = (y-y%cote)/cote;
	M[i][j] = index;
}
