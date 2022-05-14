// Chutzpa William YEUMO BARKWENDE 
// File linked to sad.c

#ifndef SAD_H
#define SAD_H 

#include <stdio.h>
#include <stdlib.h>

// On initialise la premièree couche
void init (int a, int *atrix, int **poid, int **value);

// On fait la méthode de séparation
void branch (int a, int *matrix, int **poid, int **value );

// On fait la méthode d'évaluation
// m étant la condition sur le poid
void eval (int a, int m, int **poid, int **value);

//On récupere le chemin par le binaire de la position dans la couche 
void bin (int a, int v, int u);





#endif // !SAD_H

