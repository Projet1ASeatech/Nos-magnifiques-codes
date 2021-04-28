#ifndef FUNCTION_H
#define FUNCTION_H

#define HEIGHT 17
#define WIDTH 15

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int M[HEIGHT][WIDTH], bool*, int, int, int);
void change(int M[HEIGHT][WIDTH], int, int, bool*);

int matrice(void); // initialise la matrice M

#endif
