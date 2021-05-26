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
void gravity(int M[HEIGHT][WIDTH], int i, int j, int numite)
{
    if (M[i][j] == 1)
    {
        if (M[i+1][j] == 79 || M[i+1][j] == 81)                                                 //Test si la case en-dessous est du feu et l'éteint si c'est le cas
        {
            M[i+1][j] = 89;
            M[i][j] = 20+numite;
        }                                                                                       //Vérifie la nature de la case
        else if (M[i+1][j] < M[i][j])                                                           //Test puis effectue si possible le déplacement vers le bas
        {
            int temp = M[i+1][j];
            M[i+1][j] = M[i][j];
            M[i][j] = temp;
        }
        else if (M[i][j+numite] != 70)
        {                                                                                       //Vérifie qu'il n'y ait pas de mur du côté numite
            if (M[i+1][j+numite] < M[i][j])                                                     //Test puis effectue si possible le déplacement en diagonale
            {
                int temp = M[i+1][j+numite];
                M[i+1][j+numite] = M[i][j];
                M[i][j] = temp;
            }
            else if (M[i][j+numite] < M[i][j])                                                  //Test puis effectue si possible le déplacement vers le côté
            {
                int temp = M[i][j+numite];
                M[i][j+numite] = M[i][j];
                M[i][j] = temp;
            }
        }
        else if (M[i][j-numite] != 70)
        {                                                       //Vérifie qu'il n'y ait pas de mur du côté -numite
            if (M[i+1][j-numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
            {
                int temp = M[i+1][j-numite];
                M[i+1][j-numite] = M[i][j];
                M[i][j] = temp;
            }
            else if (M[i][j-numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
            {
                int temp = M[i][j-numite];
                M[i][j-numite] = M[i][j];
                M[i][j] = temp;
            }
        }
    }
    else if (M[i][j] == 20-numite){                             //Vérifie la nature de la case
        if (i == 1){
            M[i][j] = 0;
        }
        else if (M[i-1][j] < M[i][j] || M[i-1][j] == 0)                                //Test puis effectue si possible le déplacement vers le haut
        {
            int temp = M[i-1][j];
            M[i-1][j] = 20+numite;
            M[i][j] = temp;
        }
        else if (M[i][j+numite] == 0){                          //Vérifie qu'il n'y ait pas de mur du côté numite
            if (M[i-1][j+numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale
            {
                int temp = M[i+1][j+numite];
                M[i-1][j+numite] = 20+numite;
                M[i][j] = temp;
            }
            else if (M[i][j+numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté
            {
                int temp = M[i][j+numite];
                M[i][j+numite] = 20+numite;
                M[i][j] = temp;
            }
        }
        else if (M[i][j-numite] == 0){                         //Vérifie qu'il n'y ait pas de mur du côté -numite
            if (M[i-1][j-numite] < M[i][j])                     //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
            {
                int temp = M[i+1][j-numite];
                M[i-1][j-numite] = 20+numite;
                M[i][j] = temp;
            }
            else if (M[i][j-numite] < M[i][j])                  //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
            {
                int temp = M[i][j-numite];
                M[i][j-numite] = 20+numite;
                M[i][j] = temp;
            }
        }
    }
    else if (M[i][j]==80-numite){
        if (M[i-1][j] == 90)                           	//Test puis effectue si possible le déplacement vers le bas (> car indice bois=9>8)
        {
            M[i-1][j] = 80+numite;
    	}
    	else if (M[i+1][j]==90)                       // Test puis effectue si possible le déplacement vers le haut
        {
            M[i+1][j]=80+numite;
        }
    	else if (M[i-1][j+numite] ==90)                    //Test puis effectue si possible le déplacement en diagonale vers le bas
    	{
            M[i-1][j+numite] = 80+numite;
    	}
    	else if (M[i-1][j-numite] ==90)                    //Test puis effectue si possible le déplacement en diagonale  vers le bas dans l'autre direction
    	{
            M[i-1][j-numite] = 80+numite;
    	}

        else if (M[i+1][j+numite] ==90)                    //Test puis effectue si possible le déplacement en diagonale vers le haut
    	{
            M[i+1][j+numite] = 80+numite;
    	}

    	else if (M[i+1][j-numite] ==90)                    //Test puis effectue si possible le déplacement en diagonale  vers le haut dans l'autre direction
    	{
            M[i+1][j-numite] = 80+numite;
    	}

    	else if (M[i][j+numite] ==90)                      //Test puis effectue si possible le déplacement vers le côté
    	{
            M[i][j+numite] = 80+numite;
    	}
    	else if (M[i][j-numite] ==90)      //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    	{
            M[i][j-numite] = 80+numite;
    	}
    	else if (M[i-1][j] ==89)                           	//Test puis effectue si possible le déplacement vers le bas (> car indice bois=9>8)
        {
            M[i-1][j] = 90;
    	}
    	else if (M[i+1][j]==89)                       // Test puis effectue si possible le déplacement vers le haut
        {
            M[i+1][j]=90;
        }
    	else if (M[i-1][j+numite] == 89)                    //Test puis effectue si possible le déplacement en diagonale vers le bas
    	{
            M[i-1][j+numite] = 90;
    	}
    	else if (M[i-1][j-numite] == 89)                    //Test puis effectue si possible le déplacement en diagonale  vers le bas dans l'autre direction
    	{
            M[i-1][j-numite] = 90;
    	}

        else if (M[i+1][j+numite] == 89)                    //Test puis effectue si possible le déplacement en diagonale vers le haut
    	{
            M[i+1][j+numite] = 90;
    	}

    	else if (M[i+1][j-numite] == 89)                    //Test puis effectue si possible le déplacement en diagonale  vers le haut dans l'autre direction
    	{
            M[i+1][j-numite] = 90;
    	}

    	else if (M[i][j+numite] == 89)                      //Test puis effectue si possible le déplacement vers le côté
    	{
            M[i][j+numite] = 90;
    	}
    	else if (M[i][j-numite] == 89)                  //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    	{
            M[i][j-numite] = 90;
    	}
    }
}

/* ################################################ */
/* ###              Fonction change             ### */
/* ### Parcours la matrice pour appeler gravity ### */
/* ################################################ */
void change(int M[HEIGHT][WIDTH], int numite)
{
    for (int i = HEIGHT-1; i>=0; i--)
    {
        for (int j =  WIDTH-1; j>=0; j--)
        {
            gravity(M, i, j, numite);
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
        M[i][0]=7;
        M[i][WIDTH-1]=7;
    }
    for (int j=0;j<WIDTH;j++)
    {
        M[0][j]=7;
        M[HEIGHT-1][j]=7;
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
/* ###      Fonction create_window     ### */
/* ###    Crée la fenêtre d'affichage  ### */
/* ####################################### */
void create_window(SDL_Renderer* rendu, int cote, SDL_Rect fenetre){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
    fenetre.x = 0;
    fenetre.y = 0;
    fenetre.w = (WIDTH-2)*cote+2;
    fenetre.h = (HEIGHT-2)*cote+2;
    SDL_RenderDrawRect(rendu, &fenetre);
}

/* ######################################### */
/* ###      Fonction update_affichage    ### */
/* ###        Met à jour l'affichage     ### */
/* ######################################### */
void update_affichage(int M[HEIGHT][WIDTH], SDL_Renderer* rendu, int cote)
{
    for(int k=0; k<HEIGHT-2; k++)
    {
        for(int l=0; l<WIDTH-2; l++)
        {
            if (M[k+1][l+1]==1)                                                 //Pour l'eau
                SDL_SetRenderDrawColor(rendu, 0, 0, 255, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==0)                                            //Pour l'air
                SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==79)                                           //Pour le feu
                SDL_SetRenderDrawColor(rendu, 255, 165, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==81)                                           //Pour le feu
                SDL_SetRenderDrawColor(rendu, 255, 165, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==89)                                            //Pour le bois
                SDL_SetRenderDrawColor(rendu, 88, 41, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==90)                                            //Pour le bois
                SDL_SetRenderDrawColor(rendu, 88, 41, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==70)                                            //Pour le mur
                SDL_SetRenderDrawColor(rendu, 100, 100, 100, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==19)                                            //Pour la fumée
                SDL_SetRenderDrawColor(rendu, 192, 192, 192, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==21)                                            //Pour la fumée
                SDL_SetRenderDrawColor(rendu, 192, 192, 192, SDL_ALPHA_OPAQUE);

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
