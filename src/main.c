#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

#include "file.h"
#include "reg.h"

int main (int argc, char **argv)
{
  int n_size = 0;
  int v_r = 0;
  int v_c = 0;
  if(argc != 3)
  {
    printf("Please input the name of the data.txt file and how many variables(rows/col) there are. \n");
  }
  int a = atoi(argv[2]);
  int *node = malloc(sizeof(int) * a * a); 
  int *n_exclus = malloc(sizeof(int) * a * a);
  int *matrix = malloc(sizeof(int) * a * a);
  const char* filename = argv[1];
  int b = atoi(argv[3]);

  mat_gen(filename, matrix,a);
  
  tree_building(a, b, matrix, &v_r, &v_c, &n_size, node);

  printf("Value of row: %d. Value of col: %d. \n", v_r, v_c);

  free(matrix);
  free(n_exclus);
  free(node);
  return 0;
  
}
