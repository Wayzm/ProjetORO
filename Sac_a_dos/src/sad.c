/*** Chutzpa William YEUMO BARKWENDE ***/ 
#include <stdio.h>
#include <stdlib.h>
#include "sad.h"


void branch (int a, int *matrix, int **poid, int **value)
{
  int x = 2;
  int z,zz;

  for(int i = 1; i < a ; i++)
  {

    for(int j = 0; j < x; j++)
    {
      z = poid[i-1][j];
      zz = value[i-1][j];
      poid[i][2 * j] = matrix[i] + z;
      poid[i][2 * j + 1] = z;

      value[i][2 * j] = matrix[i + a] + zz;
      value[i][2 * j + 1] = zz;

    }

    x *= 2;
  }
}

void init (int a, int *matrix, int **poid, int **value)
{
  poid[0][0] = matrix[0];
  poid[0][1] = 0;
  value[0][0] = matrix[a];
  value[0][1] = 0;

  printf(" Couche 0 :\n %d %d \n", poid[0][0], poid[0][1]);
}

void eval (int a, int **poid, int **value)
{

}
