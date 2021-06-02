#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Définition de la taille de la fenêtre en blocs (Hauteur et Largeur)
#define WIDTH 20
#define HEIGHT 28


int WinMain(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    // Renseigner la taille d'un bloc
    int cote = 25;
    // Renseigner le temps voulu entre 2 affichages (en ms)
    int time_update = 100;
    SDL_Renderer* rendu = NULL;
    SDL_Window* window = NULL;
    // Renseigner le nom de la fenêtre
    // Les dimensions de la fenêtre sont prédéfinies en fonction de cote, HEIGHT, WIDTH
    window = SDL_CreateWindow("Water falling",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              (WIDTH-2)*cote+2,
                              (HEIGHT-2)*cote+2,
                              SDL_WINDOW_SHOWN);
    rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    // Définition de la matrice M initiale
    /*
        int M[HEIGHT][WIDTH] = {{70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,70},
            {70,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,70},
            {70,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,70},
            {70,0,0,0,70,0,0,1,1,1,1,1,1,1,0,0,0,0,0,70},
            {70,0,0,70,0,70,0,0,1,1,1,1,1,0,0,0,0,0,0,70},
            {70,0,0,70,0,0,0,70,0,1,1,1,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,70,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,70,70,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,19,19,19,0,0,0,0,0,0,0,0,70,70,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,70,70,0,0,0,0,70},
            {70,0,89,89,0,0,0,0,0,0,0,0,70,70,0,0,0,0,0,70},
            {70,0,89,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,89,0,0,0,0,0,0,70,0,0,0,70,0,0,0,0,0,70},
            {70,0,89,0,0,0,0,0,0,70,0,0,0,70,0,0,0,0,0,70},
            {70,89,89,79,89,89,89,0,0,70,0,0,0,70,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,70,70,70,70,70,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70}
        };
    */
    int M[HEIGHT][WIDTH];
    matrice(M);

    // Paramètre de parité d'itération
    int numite=1;
    // Boucles
    bool running = true;
    // Type de bloc sélectionné
    int index = 0;
    while (running)
    {
        SDL_Event event;
        int x,y;
        while(SDL_PollEvent(&event))
        {
            // Fermeture de la fenêtre si on appuie sur la croix
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
            // Placement d'un nouveau pixel de type index
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    x = event.motion.x/cote;
                    y = event.motion.y/cote;
                    M[y+1][x+1] = index;
                }
            }
            if (event.type == SDL_KEYDOWN )
            {
                printf("%c",'hey');
                switch(event.key.keysym.sym)
                {
                // Fermeture de la fenêtre si on appuie sur échap
                case SDLK_ESCAPE :
                    running = false;
                    break;
                // Changement de la valeur de index selon la touche choisie
                case SDLK_KP_0:
                    index = 0;
                    break;
                case SDLK_KP_1:
                    index = 1;
                    break;
                case SDLK_KP_2:
                    index = 20+numite;
                    break;
                case SDLK_KP_7:
                    index = 70;
                    break;
                case SDLK_KP_8:
                    index = 80+numite;
                    break;
                case SDLK_KP_9:
                    index = 90+numite;
                    break;
                case SDLK_KP_5:
                    index = 50;
                    break;
                case SDLK_KP_3:
                    index = 10;
                    break;
                default :
                    break;
                }
            }
        }
        // Appel de la fonction permettant de mettre à jour M
        change(M, numite);
        // Affichage de la nouvelle matrice M
        update_affichage(M, rendu, cote);
        SDL_RenderPresent(rendu);
        SDL_Delay(time_update);
        // Changement de parité pour la prochaine itération
        numite=-numite;
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
