void gravity(int matrice[][], bool *modif, int numodif, int i, int j, int numite){
 if (matrice[i+1][j] < matrice[i][j]){                         //Test puis effectue si possible le déplacement vers le bas
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
}
