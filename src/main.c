#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "reg.h"

int main (int argc, char **argv)
{
  int check = 2;
  char str[1024];
  FILE* f;

  int l = 0;
  int i = 0; 
  int a = atoi(argv[1]);
  int *matrix = malloc(sizeof(int) * a * a);
  const char* filename = "../data.txt";

  mat_gen(f, filename, matrix);

  free(matrix);
  return 0;
  
}
