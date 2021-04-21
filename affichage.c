#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

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
    int N[10][10] = {{10,10,10,10,10,10,10,10,10,10},{10,0,0,0,0,0,0,0,0,10},{10,0,0,0,0,0,0,0,0,10},{10,0,0,0,1,1,0,0,0,10},{10,0,0,1,1,1,1,0,0,10},{10,0,1,1,1,1,1,1,0,10},{10,0,0,1,0,0,1,0,0,10},{10,0,0,0,0,0,0,0,0,10},{10,0,0,0,0,0,0,0,0,10},{10,0,0,0,0,0,0,0,0,10},{10,0,0,0,0,0,0,0,0,10},{10,10,10,10,10,10,10,10,10,10}};
    int M[8][9] = {{0,0,0,0,0,0,0,0,0},
               {0,0,1,1,0,1,1,0,0},
               {0,1,1,1,1,1,1,1,0},
               {0,1,1,1,1,1,1,1,0},
               {0,0,1,1,1,1,1,0,0},
               {0,0,0,1,1,1,0,0,0},
               {0,0,0,0,1,0,0,0,0},
               {0,0,0,0,0,0,0,0,0}};
    int hauteur_fenetre = sizeof M / sizeof M[0]-2;
    int largeur_fenetre = sizeof M[0] / sizeof(int)-2;
    int cote = 50;

    SDL_SetRenderDrawColor(rendu, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = largeur_fenetre*cote+2;
    rectangle.h = hauteur_fenetre*cote+2;
    SDL_RenderDrawRect(rendu, &rectangle);


    for(int k=0;k<=hauteur_fenetre;k++)
    {
        for(int l=0;l<=largeur_fenetre;l++)
        {
            if (M[k][l]==1)
            {
                SDL_SetRenderDrawColor(rendu, 255, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_Rect carre;
                rectangle.x = 1+(l-1)*cote;
                rectangle.y = 1+(k-1)*cote;
                rectangle.w = cote;
                rectangle.h = cote;
                SDL_RenderDrawRect(rendu, &rectangle);
                SDL_RenderFillRect(rendu, &rectangle);
            }
            if (M[k][l]==0)
            {
                SDL_SetRenderDrawColor(rendu, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_Rect carre;
                rectangle.x = 1+(l-1)*cote;
                rectangle.y = 1+(k-1)*cote;
                rectangle.w = cote;
                rectangle.h = cote;
                SDL_RenderDrawRect(rendu, &rectangle);
            }
        }
    }


    SDL_RenderPresent(rendu);

    SDL_bool programme_en_cours = SDL_TRUE;

    while(programme_en_cours)
    {

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT )
            {
                programme_en_cours = SDL_FALSE;
                printf("Bye  ");
            }
            if (event.type == SDL_KEYDOWN )
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE :
                    programme_en_cours = SDL_FALSE;
                case SDLK_EXECUTE :
                    //refresh
                default :
                    break;
                }
        }
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


