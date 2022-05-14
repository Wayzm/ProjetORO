/***   Chutzpa William YEUMO BARKWENDE             ***/

#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "sad.h"



int main ( int argc, char **argv )
{
  int a = atoi(argv[2]);
  const char *filename = argv[1];
  int *matrix = malloc(sizeof(int) * 2 * a);
  int *poid[a];
  int *value[a];
  int b = 2;

  for(int i = 0; i < a ; i++)
  { 
    b *= 2;
    poid[i] = malloc(sizeof(int) * b / 2);
    value[i] = malloc(sizeof(int) * b / 2);
  }

  mat_gen(filename, matrix, a);
  init(a, matrix, poid, value);
  branch(a, matrix, poid, value);



  
  for(int i = 0; i < a ; i++)
  {
    free(poid[i]);
    free(value[i]);
  }
  free(matrix);
  return 0;
}







