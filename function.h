#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gravity(int* matrice, bool* modif, int i, int j, int numite);
void change(int* matrice, int numite, int length, bool* modif);
void affiche(int matrice);

#endif
