void gravity(char matrice[][], int modif[], int numodif, Coordonnee immobiles[], int numimmo, int i, int j, int numite){
  Coordonnee NC;
  if (matrice[i+1][j] < matrice[i][j]){                         //Test puis effectue si possible le déplacement vers le bas
    char temp = matrice[i+1][j];
    matrice[i+1][j] = matrice[i][j];
    matrice[i][j] = temp;
    NC.x = i+1;
    NC.y = j;
    modif[numodif] = NC;                                                    //Mets à jour la matrice des modifiés
    numodif += 1;
  }
  else if (matrice[i+1][j+numite] < matrice[i][j]){             //Test puis effectue si possible le déplacement en diagonale
    char temp = matrice[i+1][j+numite];
    matrice[i+1][j+numite] = matrice[i][j];
    matrice[i][j] = temp;
    NC.x = i+1;
    NC.y = j+numite;
    modif[numodif] = NC;                                                    //Mets à jour la matrice des modifiés
    numodif += 1;
  }
  else if (matrice[i+1][j-numite] < matrice[i][j]){             //Test puis effectue si possible le déplacement en diagonale dans l'autre direction
    char temp = matrice[i+1][j-numite];
    matrice[i+1][j-numite] = matrice[i][j];
    matrice[i][j] = temp;
    NC.x = i+1;
    NC.y = j-numite;
    modif[numodif] = NC;                                                    //Mets à jour la matrice des modifiés
    numodif += 1;
  }
  else if (matrice[i][j+numite] < matrice[i][j]){               //Test puis effectue si possible le déplacement vers le côté
    char temp = matrice[i][j+numite];
    matrice[i][j+numite] = matrice[i][j];
    matrice[i][j] = temp;
    NC.x = i+1;
    NC.y = j+nummite;
    modif[numodif] = NC;                                                    //Mets à jour la matrice des modifiés
    numodif += 1;
  }
  else if (matrice[i][j-numite] < matrice[i][j]){               //Test puis effectue si possible le déplacement vers le côté dans l'autre direction
    char temp = matrice[i][j-numite];
    matrice[i][j-numite] = matrice[i][j];
    matrice[i][j] = temp;
    NC.x = i;
    NC.y = j-numite;
    modif[numodif] = NC;
    numodif += 1;
  }
  else if{                                                                  //Mets à jour la matrice des immobiles
    NC.x = i;
    NC.y = j;
    immobiles[numimmo] = NC;
    numimmo += 1;
  }
}
