// Chutzpa William YEUMO BARKWENDE
// This file only has a function to read the txt file in a specific format

#include <stdio.h>
#include <stdlib.h>

#include "file.h"

// We create a matrix which contains all the informations on our objets
void mat_gen ( const char *filename, int *matrix, int a )
{
  int i = 0;
  FILE *f;

  f = fopen(filename, "r");
  if(f==NULL)
  {
    perror("Error");
    exit(0);
  }

  while( i < a * 2)
  {
    fscanf(f, "%d", &matrix[i]);
    i++;
  }

  fclose(f);

  printf("Matrix generated. \n");
}
