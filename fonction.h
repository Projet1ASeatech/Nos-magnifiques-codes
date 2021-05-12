#ifndef FONCTION_H
#define FONCTION_H
#define WIDTH 20
#define HEIGHT 28

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int M[HEIGHT][WIDTH], bool*, int, int, int);
void change(int M[HEIGHT][WIDTH], int, bool*);
void matrice(int M[HEIGHT][WIDTH]); // initialise la matrice M
void add_water(int M[HEIGHT][WIDTH], int, int, int, int);

#endif