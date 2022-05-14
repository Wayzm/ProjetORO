/***   Chutzpa William YEUMO BARKWENDE             ***/

#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "sad.h"



int main ( int argc, char **argv )
{
  int a = atoi(argv[2]);
  int m = atoi(argv[3]);
  const char *filename = argv[1];
  int *matrix = malloc(sizeof(int) * 2 * a);
  int *poid[a];
  int *value[a];
  int b = 2;
  int c;

  if(argc != 4)
  {
    printf("Please input the data file in txt format, then the number of elements, and the weight limit. \n");
    exit(0);
  }

  for(int i = 0; i < a ; i++)
  { 
    b *= 2;
    c = b/2;
    poid[i] = malloc(c * sizeof(int));
    value[i] = malloc(c * sizeof(int));
  }

  mat_gen(filename, matrix, a);
  init(a, matrix, poid, value);
  branch(a, matrix, poid, value);
  eval(a, m, poid, value);



  
  for(int i = 0; i < a ; i++)
  {
    free(poid[i]);
    free(value[i]);
  }
  free(matrix);
  return 0;
}







