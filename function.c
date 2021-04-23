#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int matrice[9][9], bool* modif, int i, int j, int numite)
{
    if (matrice[i][j]==10 || matrice[i][j]==0){
            return 0;
    }
    else if (matrice[i+1][j] < matrice[i][j])                           //Test puis effectue si possible le déplacement vers le bas
    {
        char temp = matrice[i+1][j];
        matrice[i+1][j] = matrice[i][j];
        matrice[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (matrice[i+1][j+numite] < matrice[i][j])                    //Test puis effectue si possible le déplacement en diagonale
    {
        char temp = matrice[i+1][j+numite];
        matrice[i+1][j+numite] = matrice[i][j];
        matrice[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (matrice[i+1][j-numite] < matrice[i][j])                    //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
    {
        char temp = matrice[i+1][j-numite];
        matrice[i+1][j-numite] = matrice[i][j];
        matrice[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (matrice[i][j+numite] < matrice[i][j])                      //Test puis effectue si possible le déplacement vers le côté
    {
        char temp = matrice[i][j+numite];
        matrice[i][j+numite] = matrice[i][j];
        matrice[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    else if (matrice[i][j-numite] < matrice[i][j])                      //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    {
        char temp = matrice[i][j-numite];
        matrice[i][j-numite] = matrice[i][j];
        matrice[i][j] = temp;
        printf("i=%d et j=%d\n",i,j);
        *modif = true;
    }
    return 0;
}


void change(int matrice[9][9], int numite, int length, bool* modif)
{
    for (int i = 8; i>=0; i--)
    {
        for (int j = 8; j>=0; j--)
        {
            gravity(matrice, modif, i, j, numite);
        }
    }
    printf("modif=%d\n",*modif);
}
