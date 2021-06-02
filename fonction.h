#ifndef FONCTION_H
#define FONCTION_H
#include <SDL2/SDL.h>
#define WIDTH 20
#define HEIGHT 28

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int M[HEIGHT][WIDTH], int, int, int);                                               // Gère les déplacements des différents blocs
void change(int M[HEIGHT][WIDTH], int);                                                          // Actualise la matrice en appliquant la fonction gravity à chaque blocs
void matrice(int M[HEIGHT][WIDTH]);                                                              // Initialise la matrice M
void add_blocks(int M[HEIGHT][WIDTH], int, int, int, int);                                       // Change le type de bloc aux coordonnées x, y
void create_window(SDL_Renderer* rendu, int cote, SDL_Rect fenetre);                             // 
void update_affichage(int M[HEIGHT][WIDTH], SDL_Renderer* rendu, int cote);

#endif
