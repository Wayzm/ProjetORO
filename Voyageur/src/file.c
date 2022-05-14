#include <stdio.h>
#include <stdlib.h>

#include "file.h"

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

  while( i < a * a)
  {
    fscanf(f, "%d", &matrix[i]);
    i++;
  }

  fclose(f);

  printf("Matrix generated. \n");
}
