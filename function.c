void gravity(int matrice[][], int modif[], int numodif, Coordonnee immobiles[], int numimmo, int i, int j, int numite){
  Coordonnee NC;
  if (matrice[i][j] == 0 or matrice[i][j] == 10){
  }
  else if (matrice[i+1][j] < matrice[i][j]){                         //Test puis effectue si possible le déplacement vers le bas
    char temp = matrice[i+1][j];
    matrice[i+1][j] = matrice[i][j];
    matrice[i][j] = temp;
    modif = true;
  }
  else if (matrice[i+1][j+numite] < matrice[i][j]){             //Test puis effectue si possible le déplacement en diagonale
    char temp = matrice[i+1][j+numite];
    matrice[i+1][j+numite] = matrice[i][j];
    matrice[i][j] = temp;
  }
  else if (matrice[i+1][j-numite] < matrice[i][j]){             //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
    char temp = matrice[i+1][j-numite];
    matrice[i+1][j-numite] = matrice[i][j];
    matrice[i][j] = temp;
    modif = true;
  }
  else if (matrice[i][j+numite] < matrice[i][j]){               //Test puis effectue si possible le déplacement vers le côté
    char temp = matrice[i][j+numite];
    matrice[i][j+numite] = matrice[i][j];
    matrice[i][j] = temp;
    modif = true;
  }
  else if (matrice[i][j-numite] < matrice[i][j]){               //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    char temp = matrice[i][j-numite];
    matrice[i][j-numite] = matrice[i][j];
    matrice[i][j] = temp;
    modif = true;
  }
  else if{                                                                  //Mets à jour la matrice des immobiles
    NC.x = i;
    NC.y = j;
    immobiles[numimmo] = NC;
    numimmo += 1;
  }
}
