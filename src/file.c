#include <stdio.h>
#include <stdlib.h>


void mat_gen (FILE *f, const char *filename, int *matrix )
{
  int value;
  int i = 0;
  f = fopen(filename, "r");
  if(f==NULL)
  {
    perror("Error");
    exit(0);
  }

  while((value = fgetc(f)) != EOF)
  {
    matrix[i] = value;
    i++;
  }

  fclose(f);

  printf("Matrix generated. \n");
}
