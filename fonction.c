#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#define WIDTH 20
#define HEIGHT 28

/* ##################################### */
/* ###       Fonction gravity        ### */
/* ### Gère le déplacement des blocs ### */
/* ##################################### */
void gravity(int M[HEIGHT][WIDTH], int i, int j, int numite)
{
/* ============================ */
/* === Déplacement de l'eau === */
/* ============================ */

    if (M[i][j] == 15)                                                                           // Si la case est de l'eau
    {
        /* -------------------------- */
        /* --- Extinction du feu --- */
        /* -------------------------- */
        if (M[i+1][j] == 79 || M[i+1][j] == 81)                                                 // Si la case en-dessous est du feu
        {
            M[i+1][j] = 910+numite;                                                             // On éteint le feu qui redevient du bois
            M[i][j] = 20+numite;                                                                // L'eau devient de la vapeur
        }
        else if (M[i+1][j] < M[i][j])                                                           // Test possibilité de déplacement vers le bas
        {
            int temp = M[i+1][j];
            M[i+1][j] = M[i][j];
            M[i][j] = temp;
        }
        else if (M[i][j+numite] != 70)                                                          // Si la case côté parité n'est pas du mur
        {
            if (M[i+1][j+numite] < M[i][j])                                                     // Test possibilité de déplacement en diagonale
            {
                int temp = M[i+1][j+numite];
                M[i+1][j+numite] = M[i][j];
                M[i][j] = temp;
            }
            else if (M[i][j+numite] < M[i][j])                                                  // Test possibilité de déplacement de côté
            {
                int temp = M[i][j+numite];
                M[i][j+numite] = M[i][j];
                M[i][j] = temp;
            }
        }
        else if (M[i][j-numite] != 70)                                                          // Si la case côté opposé à parité n'est pas du mur
        {
            if (M[i+1][j-numite] < M[i][j]){                                                    // Test possibilité de déplacement en diagonale
                int temp = M[i+1][j-numite];
                M[i+1][j-numite] = M[i][j];
                M[i][j] = temp;
            }
            else if (M[i][j-numite] < M[i][j])                                                  // Test possibilité de déplacement de côté
            {
                int temp = M[i][j-numite];
                M[i][j-numite] = M[i][j];
                M[i][j] = temp;
            }
        }
    }

/* ================================ */
/* === Déplacement de la vapeur === */
/* ================================ */
    else if (M[i][j] == 20-numite)                                                              // Si la case est de la vapeur
    {
        if (i == 1)                                                                             // Si on est en haut de l'écran
        {
            M[i][j] = 0;                                                                        // Fait disparaitre la case de vapeur
        }
        else if (M[i-1][j] < M[i][j] || M[i-1][j] == 0)                                         // Test possibilité de déplacement vers le haut
        {
            int temp = M[i-1][j];
            M[i-1][j] = 20+numite;
            M[i][j] = temp;
        }
        else if (M[i][j+numite] == 0)                                                           // Si la case côté parité n'est pas du mur
        {
            if (M[i-1][j+numite] < M[i][j])                                                     // Test possibilité de déplacement en diagonale
            {
                int temp = M[i+1][j+numite];
                M[i-1][j+numite] = 20+numite;
                M[i][j] = temp;
            }
            else if (M[i][j+numite] < M[i][j])                                                  // Test possibilité de déplacement de côté
            {
                int temp = M[i][j+numite];
                M[i][j+numite] = 20+numite;
                M[i][j] = temp;
            }
        }
        else if (M[i][j-numite] == 0)                                                           // Si la case côté opposé à parité n'est pas du mur
        {
            if (M[i-1][j-numite] < M[i][j])                                                     // Test possibilité de déplacement en diagonale
            {
                int temp = M[i+1][j-numite];
                M[i-1][j-numite] = 20+numite;
                M[i][j] = temp;
            }
            else if (M[i][j-numite] < M[i][j])                                                  // Test possibilité de déplacement de côté
            {
                int temp = M[i][j-numite];
                M[i][j-numite] = 20+numite;
                M[i][j] = temp;
            }
        }
    }

/* ========================== */
/* === Déplacement du feu === */
/* ========================== */
    else if (M[i][j]==80-numite)                                                                // Si la case est du feu
    {
        /* ------------------------------------------- */
        /* --- Propagation du feu dans du bois sec --- */
        /* ------------------------------------------- */
        if (M[i-1][j] == 900-numite)                                                                 	// Test possibilité de déplacement vers le haut
        {
            M[i-1][j] = 80+numite;
        }
        else if (M[i+1][j] == 900-numite)                                                                 // Test possibilité de déplacement vers le bas
        {
            M[i+1][j]=80+numite;
        }
        else if (M[i-1][j+numite] == 900-numite)                                                         // Test possibilité de déplacement en diagonale haute côté parité
        {
            M[i-1][j+numite] = 80+numite;
        }
        else if (M[i-1][j-numite] == 900-numite)                                                         // Test possibilité de déplacement en diagonale haute côté opposé parité
        {
            M[i-1][j-numite] = 80+numite;
        }
        else if (M[i+1][j+numite] == 900-numite)                                                         // Test possibilité de déplacement en diagonale basse côté parité
        {
            M[i+1][j+numite] = 80+numite;
        }
        else if (M[i+1][j-numite] == 900-numite)                                                         // Test possibilité de déplacement en diagonale basse côté opposé parité
        {
            M[i+1][j-numite] = 80+numite;
        }
        else if (M[i][j+numite] == 900-numite)                                                           // Test possibilité de déplacement de côté parité
        {
            M[i][j+numite] = 80+numite;
        }
        else if (M[i][j-numite] == 900-numite)                                                           // Test possibilité de déplacement de côté opposé parité
        {
            M[i][j-numite] = 80+numite;
        }
/* ----------------------- */
/* --- Séchage du bois --- */
/* ----------------------- */
        else if (M[i-1][j] == 910-numite)
        {
            M[i-1][j] = 900+numite;
        }
        else if (M[i+1][j] == 910-numite)
        {
            M[i+1][j]=900+numite;
        }
        else if (M[i-1][j+numite] == 910-numite)
        {
            M[i-1][j+numite] = 900+numite;
        }
        else if (M[i-1][j-numite] == 910-numite)
        {
            M[i-1][j-numite] = 900+numite;
        }
        else if (M[i+1][j+numite] == 910-numite)
        {
            M[i+1][j+numite] = 900+numite;
        }
        else if (M[i+1][j-numite] == 910-numite)
        {
            M[i+1][j-numite] = 900+numite;
        }
        else if (M[i][j+numite] == 910-numite)
        {
            M[i][j+numite] = 900+numite;
        }
        else if (M[i][j-numite] == 910-numite)
        {
            M[i][j-numite] = 900+numite;
        }
        else
        {
            M[i][j] = 80+numite;
        }
    }
/* ============================ */
/* === Déplacement du sable === */
/* ============================ */
    else if (M[i][j] == 50)                                                                     // Si la case est du sable
    {
        if (M[i+1][j] == 80+numite || M[i+1][j] == 80-numite)
        {
            M[i+1][j] = 910+numite;                                                             // On éteint le feu qui redevient du bois
        }
        else if (M[i+1][j] < M[i][j])                                                           // Test possibilité de déplacement vers le bas
        {
            int temp = M[i+1][j];
            M[i+1][j] = M[i][j];
            M[i][j] = temp;
        }
        else if (M[i][j+numite] < 70 )                                                          // Si la case côté parité n'est pas du mur, du bois ou du bois brulant
        {
            if (M[i+1][j+numite] < M[i][j])                                                     // Test possibilité de déplacement en diagonale côté parité
            {
                int temp = M[i+1][j+numite];
                M[i+1][j+numite] = M[i][j];
                M[i][j] = temp;
            }
        }
    }
/* ============================== */
/* === Déplacement de l'huile === */
/* ============================== */
    else if (M[i][j] == 10)                                                                      // Si la case est de l'huile
    {
        if (M[i+1][j] < M[i][j])                                                                 // Test possibilité de déplacement vers le bas
        {
            int temp = M[i+1][j];
            M[i+1][j] = 10;
            M[i][j] = temp;
        }
        else if (M[i][j+numite] != 70)                                                           // Si la case côté parité n'est pas du mur
        {
            if (M[i+1][j+numite] < M[i][j])                                                      // Test possibilité de déplacement en diagonale
            {
                int temp = M[i+1][j+numite];
                M[i+1][j+numite] = M[i][j];
                M[i][j] = temp;
            }
            else if (M[i][j+numite] < M[i][j])                                                   // Test possibilité de déplacement de côté
            {
                int temp = M[i][j+numite];
                M[i][j+numite] = M[i][j];
                M[i][j] = temp;
            }
        }
        else if (M[i][j-numite] != 70)                                                           // Si la case côté opposé à parité n'est pas du mur
        {
            if (M[i+1][j-numite] < M[i][j])                                                      // Test possibilité de déplacement en diagonale
            {
                int temp = M[i+1][j-numite];
                M[i+1][j-numite] = M[i][j];
                M[i][j] = temp;
            }
            else if (M[i][j-numite] < M[i][j])                                                   // Test possibilité de déplacement de côté
            {
                int temp = M[i][j-numite];
                M[i][j-numite] = M[i][j];
                M[i][j] = temp;
            }
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
void matrice(int M[HEIGHT][WIDTH])
{
    for (int i=0; i<HEIGHT; i++)
    {
        M[i][0]=70;
        M[i][WIDTH-1]=70;
    }
    for (int j=0; j<WIDTH; j++)
    {
        M[0][j]=70;
        M[HEIGHT-1][j]=70;
    }
    for (int p=1; p<HEIGHT-1; p++)
    {
        for (int q=1; q<WIDTH-1; q++)
            M[p][q]=0;
    }
}

/* ##################################### */
/* ###      Fonction add_blocks      ### */
/* ###    Ajoute de nouveaux blocs   ### */
/* ##################################### */
void add_blocks(int M[HEIGHT][WIDTH], int x, int y, int cote, int index)
{
    int i = (x-x%cote)/cote;
    int j = (y-y%cote)/cote;
    M[i][j] = index;
}

/* ####################################### */
/* ###      Fonction create_window     ### */
/* ###    Crée la fenêtre d'affichage  ### */
/* ####################################### */
void create_window(SDL_Renderer* rendu, int cote, SDL_Rect fenetre)
{
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
            if (M[k+1][l+1]==15)                                                                 // Pour l'eau
                SDL_SetRenderDrawColor(rendu, 0, 0, 255, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==0)                                                             // Pour l'air
                SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==79)                                                            // Pour le feu
                SDL_SetRenderDrawColor(rendu, 255, 165, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==81)                                                            // Pour le feu
                SDL_SetRenderDrawColor(rendu, 255, 165, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==899)                                                            // Pour le bois
                SDL_SetRenderDrawColor(rendu, 88, 41, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==901)                                                            // Pour le bois
                SDL_SetRenderDrawColor(rendu, 88, 41, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==911)                                                            // Pour le bois
                SDL_SetRenderDrawColor(rendu, 88, 41, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==909)                                                            // Pour le bois
                SDL_SetRenderDrawColor(rendu, 88, 41, 0, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==70)                                                            // Pour le mur
                SDL_SetRenderDrawColor(rendu, 100, 100, 100, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==19)                                                            // Pour la fumée
                SDL_SetRenderDrawColor(rendu, 192, 192, 192, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==21)                                                            // Pour la fumée
                SDL_SetRenderDrawColor(rendu, 192, 192, 192, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==50)                                                            // Pour le sable
                SDL_SetRenderDrawColor(rendu, 255, 255, 102, SDL_ALPHA_OPAQUE);
            else if (M[k+1][l+1]==10)                                                            // Pour l'huile
                SDL_SetRenderDrawColor(rendu, 128, 128, 0, SDL_ALPHA_OPAQUE);

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
