#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Définition de la taille de la fenêtre en blocs (Hauteur et Largeur)


int WinMain(int argc, char* argv[])
{
    bool running = true;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer* rendu;
    SDL_Renderer* rendu_menu;
    SDL_Window* menu;
    SDL_Window* window;
    SDL_Texture *texture;
    SDL_Texture *texture2;
    SDL_Surface *intro;
    SDL_Surface *background;
    SDL_Surface *logo;
    SDL_Rect rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 460;
    rectangle.h = 500;
    int cote = 10;                                                                                  // Renseigner la taille d'un bloc
    int time_update = 100;


    // Définition de la matrice M de test
//    int M[HEIGHT][WIDTH] ={
//        {70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,15,15,0,15,15,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,15,15,15,15,15,15,15,0,0,0,0,0,70},
//        {70,0,0,0,0,0,15,15,15,15,15,15,15,15,15,0,0,0,0,70},
//        {70,0,0,0,0,0,15,15,15,15,15,15,15,15,15,0,0,0,0,70},
//        {70,0,0,0,70,0,0,15,15,15,15,15,15,15,0,0,0,0,0,70},
//        {70,0,0,70,0,70,0,0,15,15,15,15,15,0,0,0,0,0,0,70},
//        {70,0,0,70,0,0,0,70,0,15,15,15,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,70,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,70,70,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,19,19,19,0,0,0,0,0,0,0,0,70,70,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,70,70,0,0,0,0,70},
//        {70,0,89,89,0,0,0,0,0,0,0,0,70,70,0,0,0,0,0,70},
//        {70,0,89,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,89,0,0,0,0,0,0,70,0,0,0,70,0,0,0,0,0,70},
//        {70,0,89,0,0,0,0,0,0,70,0,0,0,70,0,0,0,0,0,70},
//        {70,89,89,79,89,89,89,0,0,70,0,0,0,70,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,70,70,70,70,70,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70},
//        {70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70}
//    };


    // Renseigner le temps voulu entre 2 affichages (en ms)

    menu = SDL_CreateWindow("Menu",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            720,
                            240,
                            SDL_WINDOW_SHOWN);
    rendu_menu = SDL_CreateRenderer(menu, -1, SDL_RENDERER_SOFTWARE);

    intro = SDL_LoadBMP("./img/intro.bmp");
    texture2 = SDL_CreateTextureFromSurface(rendu_menu, intro);
    SDL_RenderCopy(rendu_menu, texture2, NULL, NULL);
    SDL_RenderPresent(rendu_menu);
    SDL_Delay(1000);

    while (running)
    {
        SDL_Event event;                                                                                 // Placement d'un nouveau pixel de type index
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)                                                            // Fermeture de la fenêtre si on appuie sur la croix
            {
                return 0;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if ((event.button.button==SDL_BUTTON_LEFT)&&(event.motion.y>=30 && event.motion.y<=210))
                {
                    if (event.motion.x>=50 && event.motion.x<=230)
                    {
                        cote = 10;
                        HEIGHT = 520/cote;
                        WIDTH = 480/cote;
                        running = false;
                        break;
                    }
                    else if (event.motion.x>=270 && event.motion.x<=450)
                    {
                        cote = 20;
                        HEIGHT = 540/cote;
                        WIDTH = 500/cote;
                        running = false;
                        break;
                    }
                    else if (event.motion.x>=490 && event.motion.x<=670)
                    {
                        cote = 25;
                        HEIGHT = 550/cote;
                        WIDTH = 510/cote;
                        running = false;
                        break;
                    }
                }
            }
            SDL_Delay(10);
        }
    }

    int M[HEIGHT][WIDTH];                                                                         // Initialisation d'une matrice de dimension WIDTH*HEIGHT
    matrice(M);

    // Remplissage de la matrice
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(intro);
    SDL_DestroyRenderer(rendu_menu);
    SDL_DestroyWindow(menu);


    window = SDL_CreateWindow("Sea'Mula'Tech",                                                      // Renseigner le nom de la fenêtre
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          480,                                                                  // Les dimensions de la fenêtre sont prédéfinies en fonction de cote, HEIGHT, WIDTH
                          720,
                          SDL_WINDOW_SHOWN);
    rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    logo = SDL_LoadBMP("./img/logo.bmp");
    SDL_SetWindowIcon(menu, logo);
    SDL_SetWindowIcon(window,logo);
    SDL_FreeSurface(logo);

    background = SDL_LoadBMP("./img/background.bmp");
    texture = SDL_CreateTextureFromSurface(rendu, background);
    SDL_RenderCopy(rendu, texture, NULL, NULL);
    SDL_RenderPresent(rendu);

    running = true;

    int numite=1;                                                                                   // Paramètre de parité d'itération                                                                           // Boucles
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
                if (event.motion.y>=530 && event.motion.y<=604)
                {
                    if (event.motion.x>=14 && event.motion.x<=88)
                    {
                        matrice(M);
                        break;
                    }
                    if (event.motion.x>=108 && event.motion.x<=183)
                    {
                        index = 20+numite;
                        break;
                    }
                    if (event.motion.x>=202 && event.motion.x<=277)
                    {
                        index = 15+numite;
                        break;
                    }
                    if (event.motion.x>=296 && event.motion.x<=371)
                    {
                        index = 50;
                        break;
                    }
                    if (event.motion.x>=390 && event.motion.x<=465)
                    {
                        index = 70;
                        break;
                    }
                }
                if (event.motion.y>=604 && event.motion.y<=702)
                {
                    if (event.motion.x>=14 && event.motion.x<=88)
                    {
                        index = 0;
                        break;
                    }
                    if (event.motion.x>=108 && event.motion.x<=183)
                    {
                        index = 910+numite;
                        break;
                    }
                    if (event.motion.x>=202 && event.motion.x<=277)
                    {
                        index = 80+numite;
                        break;
                    }
                    if (event.motion.x>=296 && event.motion.x<=371)
                    {
                        index = 10+numite;
                        break;
                    }
                    if (event.motion.x>=390 && event.motion.x<=465)
                    {
                        //index = ;
                        break;
                    }
                }
            }
            if (event.type == SDL_KEYDOWN )
            {
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
                case SDLK_KP_2:
                    index = 15+numite;
                    break;
                case SDLK_2:
                    index = 15+numite;
                    break;
                case SDLK_KP_1:
                    index = 20+numite;                                                              // Prise en compte de la parité pour les matières concernées
                    break;
                case SDLK_1:
                    index = 20+numite;
                    break;
                case SDLK_KP_8:
                    index = 10+numite;
                    break;
                case SDLK_8:
                    index = 10+numite;
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
                case SDLK_TAB:
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
        numite=-numite;                                                                             // Changement de parité pour la prochaine itération
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
