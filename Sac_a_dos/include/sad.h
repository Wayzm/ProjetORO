#ifndef SAD_H
#define SAD_H 

#include <stdio.h>
#include <stdlib.h>

// On initialise la premièree couche
void init (int a, int *atrix, int **poid, int **value);

// On fait la méthode de séparation
void branch (int a, int *matrix, int **poid, int **value );

// On fait la méthode d'évaluation
void eval (int a, int **poid, int **value);


#endif // !SAD_H

