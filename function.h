#ifndef FONCTION_H
#define FONCTION_H
#define WIDTH 9
#define HEIGHT 9

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int M[SIZE][SIZE], bool*, int, int, int);
void change(int M[SIZE][SIZE], int, int, bool*);
void affiche(int M[SIZE][SIZE]);
int matrice(void); // initialise la matrice M

#endif
