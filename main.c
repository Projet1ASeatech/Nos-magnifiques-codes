#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define HEIGHT 28
#define WIDTH 20

int WinMain(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
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

    SDL_RenderPresent(rendu);
    SDL_Delay(10);
    int numite=1;
    bool running = true;
    int index = 0;
    while (running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            int x,y;
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button==SDL_BUTTON_LEFT){
                    x = event.motion.x/cote;
                    y = event.motion.y/cote;
                    M[y+1][x+1] = index;

                }
            }
            if (event.type == SDL_QUIT )
            {
                running = false;
                break;
            }
            if (event.type == SDL_KEYDOWN )
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE :
                    running = false;
                    break;
                case SDLK_EXECUTE :
                //refresh
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
                default :
                    break;
                }
            SDL_SetRenderDrawColor(rendu, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(rendu);
            SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(rendu, &fenetre);
            SDL_RenderPresent(rendu);
            change(M, numite);
            SDL_Delay(10);

            update_affichage(M, rendu, cote);

            SDL_RenderPresent(rendu);
            SDL_Delay(100);
            numite=-numite;
        }
        SDL_RenderPresent(rendu);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
