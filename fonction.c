#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
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
    else if (M[i][j] == 1)
    {                                                           //Vérifie la nature de la case
        if (M[i+1][j] < M[i][j])                           //Test puis effectue si possible le déplacement vers le bas
        {
            char temp = M[i+1][j];
            M[i+1][j] = M[i][j];
            M[i][j] = temp;
            *modif = true;
        }
        else if (M[i][j+numite] != 10)
        {                                                       //Vérifie qu'il n'y ait pas de mur du côté numite
            if (M[i+1][j+numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale
            {
                char temp = M[i+1][j+numite];
                M[i+1][j+numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
            else if (M[i][j+numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté
            {
                char temp = M[i][j+numite];
                M[i][j+numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
        }
        else if (M[i][j-numite] != 10)
        {                                                       //Vérifie qu'il n'y ait pas de mur du côté -numite
            if (M[i+1][j-numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
            {
                char temp = M[i+1][j-numite];
                M[i+1][j-numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
            else if (M[i][j-numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
            {
                char temp = M[i][j-numite];
                M[i][j-numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
        }
    }
    else if (M[i][j] == 2){                                     //Vérifie la nature de la case
        if (M[i-1][j] < M[i][j])                           //Test puis effectue si possible le déplacement vers le haut
        {
            char temp = M[i-1][j];
            M[i-1][j] = M[i][j];
            M[i][j] = temp;
            *modif = true;
        }
        else if (M[i][j+numite] != 10){                         //Vérifie qu'il n'y ait pas de mur du côté numite
            if (M[i-1][j+numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale
            {
                char temp = M[i+1][j+numite];
                M[i-1][j+numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
            else if (M[i][j+numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté
            {
                char temp = M[i][j+numite];
                M[i][j+numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
        }
        else if (M[i][j-numite] != 10){                         //Vérifie qu'il n'y ait pas de mur du côté -numite
            if (M[i-1][j-numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
            {
                char temp = M[i+1][j-numite];
                M[i-1][j-numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
            else if (M[i][j-numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
            {
                char temp = M[i][j-numite];
                M[i][j-numite] = M[i][j];
                M[i][j] = temp;
                *modif = true;
            }
        }
    }
    else if (M[i][j]==8){
        if (M[i-1][j] ==9)                           	//Test puis effectue si possible le déplacement vers le bas (> car indice bois=9>8)
        {
            char temp = M[i-1][j];
            M[i-1][j] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
    	
    	else if (M[i+1][j]==9)                       // Test puis effectue si possible le déplacement vers le bas
        {
            char temp=M[i+1][j];
            M[i+1][j]=M[i][j];
            M[i][j]=temp;
            *modif=true;
        }
    	else if (M[i-1][j+numite] ==9)                    //Test puis effectue si possible le déplacement en diagonale vers le bas
    	{
            char temp = M[i-1][j+numite];
            M[i-1][j+numite] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
    	else if (M[i-1][j-numite] ==9)                    //Test puis effectue si possible le déplacement en diagonale  vers le bas dans l'autre direction
    	{
            char temp = M[i-1][j-numite];
            M[i-1][j-numite] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
    	
        else if (M[i+1][j+numite] ==9)                    //Test puis effectue si possible le déplacement en diagonale vers le haut
    	{
            char temp = M[i+1][j+numite];
            M[i+1][j+numite] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
    	
    	else if (M[i+1][j-numite] ==9)                    //Test puis effectue si possible le déplacement en diagonale  vers le haut dans l'autre direction
    	{
            char temp = M[i+1][j-numite];
            M[i+1][j-numite] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
    	
    	else if (M[i][j+numite] ==9)                      //Test puis effectue si possible le déplacement vers le côté
    	{
            char temp = M[i][j+numite];
            M[i][j+numite] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
    	else if (M[i][j-numite] ==9)      //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    	{
            char temp = M[i][j-numite];
            M[i][j-numite] = M[i][j];
            M[i][j] = temp;
            *modif = true;
    	}
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
        M[i][WIDTH-1]=10;
    }
    for (int j=0;j<WIDTH;j++)
    {
        M[0][j]=10;
        M[HEIGHT-1][j]=10;
    }
    for (int p=1;p<HEIGHT-1;p++)
    {
        for (int q=1;q<WIDTH-1;q++)
            M[p][q]=0;
    }
}

/* ##################################### */
/* ###      Fonction add_blocks      ### */
/* ###    Ajoute de nouveaux blocs   ### */
/* ##################################### */
void add_blocks(int M[HEIGHT][WIDTH], int x, int y, int cote, int index){
	int i = (x-x%cote)/cote;
	int j = (y-y%cote)/cote;
	M[i][j] = index;
}

/* ####################################### */
/* ###      Fonction update_affichage  ### */
/* ###    Met à jour l'affichage       ### */
/* ####################################### */
void update_affichage(int M[HEIGHT][WIDTH], SDL_Renderer* rendu, int cote)
{
    for(int k=0; k<HEIGHT; k++)
    {
        for(int l=0; l<WIDTH; l++)
        {
            if (M[k+1][l+1]==1)
                SDL_SetRenderDrawColor(rendu, 0, 0, 255, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==0)
                SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==10)
                SDL_SetRenderDrawColor(rendu, 100, 100, 100, SDL_ALPHA_OPAQUE);

            SDL_Rect carre;
            carre.x = 1+(l)*cote;
            carre.y = 1+(k)*cote;
            carre.w = cote;
            carre.h = cote;
            SDL_RenderDrawRect(rendu, &carre);
            SDL_RenderFillRect(rendu, &carre);
        }
    }
}
