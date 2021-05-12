#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define HEIGHT 28
#define WIDTH 20

int WinMain(int argc, char* argv[])
{
    int cote = 25;
    SDL_Renderer* rendu = NULL;
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("Water falling",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              (WIDTH-2)*cote+2,
                              (HEIGHT-2)*cote+2,
                              SDL_WINDOW_SHOWN);
    rendu = SDL_CreateRenderer(window,
                               -1, // driver
                               SDL_RENDERER_SOFTWARE);
    SDL_Rect fenetre;
    create_window(rendu, cote, fenetre);

    int M[HEIGHT][WIDTH] = {{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,10},
        {10,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,10},
        {10,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,10},
        {10,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,10,10,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,10,10,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,10,0,0,0,10,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,10,0,0,0,10,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,10,0,0,0,10,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10},
        {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10}
    };

    SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect fenetre;
    fenetre.x = 0;
    fenetre.y = 0;
    fenetre.w = (WIDTH-2)*cote+2;
    fenetre.h = (HEIGHT-2)*cote+2;
    SDL_RenderDrawRect(rendu, &fenetre);

    SDL_RenderPresent(rendu);
    SDL_Delay(10);
    int numite=1;
    bool running = true;
    bool modif = true;
    bool* ptr_modif = &modif;
    while (running)
    {
        modif=true;
        while (modif)
        {
            SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(rendu);
            SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(rendu, &fenetre);
            modif=false;
            change(M, numite, ptr_modif);
            SDL_Delay(10);
             
            update_affichage(M, rendu, cote);
            
            SDL_RenderPresent(rendu);
            SDL_Delay(100);
            numite=-numite;
        }

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT )
            {
                running = false;
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
        SDL_Delay(100);
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
