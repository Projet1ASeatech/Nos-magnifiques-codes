#include "Coordonne.h"
#include "Function.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int M[10][10] = {{10,10,10,10,10,10,10,10,10,10},{10,0,0,0,0,0,0,0,0,10},
                   {10,0,0,0,0,0,0,0,0,10},{10,0,0,0,1,1,0,0,0,10},
                   {10,0,0,1,1,1,1,0,0,10},{10,0,1,1,1,1,1,1,0,10},
                   {10,0,0,1,0,0,1,0,0,10},{10,0,0,0,0,0,0,0,0,10},
                   {10,0,0,0,0,0,0,0,0,10},{10,0,0,0,0,0,0,0,0,10},
                   {10,0,0,0,0,0,0,0,0,10},{10,10,10,10,10,10,10,10,10,10}}
  int numint=1;
  bool running = True;
  while running{
    bool modifie=true;
    while modifie{
      modifie=false;
      change(M);
      affiche(M);
      numint=-numnint
  }
}
