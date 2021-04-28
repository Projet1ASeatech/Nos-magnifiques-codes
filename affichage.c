#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SIZE 9

int WinMain(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window=NULL;
    window=SDL_CreateWindow("Hello",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            1200,
                            900,
                            SDL_WINDOW_SHOWN);

    SDL_Renderer* rendu=NULL;
    rendu=SDL_CreateRenderer(window,
                             -1, // driver
                             SDL_RENDERER_SOFTWARE);

    int M[SIZE][SIZE] = {{10,10,10,10,10,10,10,10,10},
        {10,0,1,1,0,1,1,0,10},
        {10,1,1,1,1,1,1,1,10},
        {10,1,1,1,1,1,1,1,10},
        {10,0,1,1,1,1,1,0,10},
        {10,0,0,1,1,1,0,0,10},
        {10,0,0,0,1,0,0,0,10},
        {10,0,0,0,0,0,0,0,10},
        {10,10,10,10,10,10,10,10,10}
    };



    int hauteur_fenetre = sizeof M / sizeof M[0]-2;
    int largeur_fenetre = sizeof M[0] / sizeof(int)-2;
    int cote = 50;

    SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect fenetre;
    fenetre.x = 0;
    fenetre.y = 0;
    fenetre.w = largeur_fenetre*cote+2;
    fenetre.h = hauteur_fenetre*cote+2;
    SDL_RenderDrawRect(rendu, &fenetre);
    for(int k=0; k<hauteur_fenetre; k++)
    {
        for(int l=0; l<largeur_fenetre; l++)
        {
            if (M[k+1][l+1]==1)
            {
                SDL_SetRenderDrawColor(rendu, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_Rect carre;
                carre.x = 1+(l)*cote;
                carre.y = 1+(k)*cote;
                carre.w = cote;
                carre.h = cote;
                SDL_RenderDrawRect(rendu, &carre);
                SDL_RenderFillRect(rendu, &carre);
            }
            if (M[k+1][l+1]==0)
            {
                SDL_SetRenderDrawColor(rendu, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_Rect carre;
                carre.x = 1+(l)*cote;
                carre.y = 1+(k)*cote;
                carre.w = cote;
                carre.h = cote;
                SDL_RenderDrawRect(rendu, &carre);
            }
        }
    }
    SDL_RenderPresent(rendu);
    SDL_Delay(1000);
    int numite=1;
    bool running = true;
    bool modif = true;
    bool* ptr_modif = &modif;
    int length = sizeof M[0];
    while (running)
    {
        modif=true;
        while (modif)
        {
            SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(rendu);
            SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(rendu, &fenetre);
            SDL_RenderPresent(rendu);
            modif=false;
            change(M, numite, length, ptr_modif);
            SDL_Delay(10);
            for(int k=0; k<hauteur_fenetre; k++)
            {
                for(int l=0; l<largeur_fenetre; l++)
                {
                    if (M[k+1][l+1]==1)
                    {
                        SDL_SetRenderDrawColor(rendu, 255, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_Rect carre;
                        carre.x = 1+(l)*cote;
                        carre.y = 1+(k)*cote;
                        carre.w = cote;
                        carre.h = cote;
                        SDL_RenderDrawRect(rendu, &carre);
                        SDL_RenderFillRect(rendu, &carre);
                    }
                    if (M[k+1][l+1]==0)
                    {
                        SDL_SetRenderDrawColor(rendu, 255, 255, 255, SDL_ALPHA_OPAQUE);
                        SDL_Rect carre;
                        carre.x = 1+(l)*cote;
                        carre.y = 1+(k)*cote;
                        carre.w = cote;
                        carre.h = cote;
                        SDL_RenderDrawRect(rendu, &carre);
                    }
                }
            }
            SDL_RenderPresent(rendu);
            SDL_Delay(1000);
            numite=-numite;
        }
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT )
            {
                running = false;
                printf("Bye  ");
            }
            if (event.type == SDL_KEYDOWN )
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE :
                    running = false;
                case SDLK_EXECUTE :
                //refresh
                default :
                    break;
                }
        }
        SDL_RenderPresent(rendu);
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
