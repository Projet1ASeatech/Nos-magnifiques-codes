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
    int cote = 25;                                                                                  // Renseigner la taille d'un bloc
    int time_update = 100;                                                                          // Renseigner le temps voulu entre 2 affichages (en ms)
    SDL_Renderer* rendu;
    SDL_Window* window;
    window = SDL_CreateWindow("Water falling",                                                      // Renseigner le nom de la fenêtre
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              (WIDTH-2)*cote+2,                                                     // Les dimensions de la fenêtre sont prédéfinies en fonction de cote, HEIGHT, WIDTH
                              (HEIGHT-2)*cote+2,
                              SDL_WINDOW_SHOWN);
    rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    
    SDL_Surface *surface;
    surface = SDL_LoadBMP("./img/logo.bmp");
    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);
    
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
            {70,0,911,911,0,0,0,0,0,0,0,0,70,70,0,0,0,0,0,70},
            {70,0,911,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,911,0,0,0,0,0,0,70,0,0,0,70,0,0,0,0,0,70},
            {70,0,911,0,0,0,0,0,0,70,0,0,0,70,0,0,0,0,0,70},
            {70,911,911,79,911,911,911,0,0,70,0,0,0,70,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,70,70,70,70,70,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
            {70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70}
        };
    */
    int M[HEIGHT][WIDTH];                                                                           // Initialisation d'une matrice de dimension WIDTH*HEIGHT
    matrice(M);                                                                                     // Remplissage de la matrice
    int numite=1;                                                                                   // Paramètre de parité d'itération
    bool running = true;                                                                            // Boucles
    int index = 0;
    while (running)
    {
        SDL_Event event;
        int x,y;                                                                                    // Placement d'un nouveau pixel de type index
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT )                                                            // Fermeture de la fenêtre si on appuie sur la croix
            {
                running = false;
                break;
            }
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
                case SDLK_ESCAPE :                                                                  // Fermeture de la fenêtre si on appuie sur échap
                    running = false;
                    break;
                case SDLK_KP_5:                                                                     // Changement de la valeur de index selon la touche choisie
                    index = 0;
                    break;
                case SDLK_5:
                    index = 0;
                    break;
                case SDLK_KP_1:
                    index = 15;
                    break;
                case SDLK_1:
                    index = 15;
                    break;
                case SDLK_KP_8:
                    index = 20+numite;                                                              // Prise en compte de la parité pour les matières concernées
                    break;
                case SDLK_8:
                    index = 20+numite;
                    break;
                case SDLK_KP_2:
                    index = 10;
                    break;
                case SDLK_2:
                    index = 10;
                    break;
                case SDLK_KP_3:
                    index = 50;
                    break;
                case SDLK_3:
                    index = 50;
                    break;
                case SDLK_KP_4:
                    index = 70;
                    break;
                case SDLK_4:
                    index = 70;
                    break;
                case SDLK_KP_7:
                    index = 80+numite;
                    break;
                case SDLK_7:
                    index = 80+numite;
                    break;
                case SDLK_KP_6:
                    index = 910+numite;
                    break;
                case SDLK_6:
                    index = 910+numite;
                    break;
                case SDLK_TAB:                                                                     // permet de reset la page en plus du bouton preset
                    matrice(M);
                    break;
                default :
                    break;
                }
            }
        }
        change(M, numite);                                                                          // Appel de la fonction permettant de mettre à jour M
        update_affichage(M, rendu, cote);                                                           // Affichage de la nouvelle matrice M
        SDL_RenderPresent(rendu);
        SDL_Delay(time_update);
        numite=-numite;                                                                            // Changement de parité pour la prochaine itération
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
