#ifndef FONCTION_H
#define FONCTION_H
#include <SDL2/SDL.h>
int WIDTH;
int HEIGHT;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int M[HEIGHT][WIDTH], int, int, int);
void change(int M[HEIGHT][WIDTH], int);
void matrice(int M[HEIGHT][WIDTH]); // initialise la matrice M
void add_blocks(int M[HEIGHT][WIDTH], int, int, int, int);
void create_window(SDL_Renderer* rendu, int cote, SDL_Rect fenetre);
void update_affichage(int M[HEIGHT][WIDTH], SDL_Renderer* rendu, int cote);

#endif
