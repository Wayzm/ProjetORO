/*** Chutzpa William YEUMO BARKWENDE ***/ 
#include <stdio.h>
#include <stdlib.h>
#include "sad.h"

void bin(int a, int v)
{
  int i;
  int l; 
  int tab[32];
  printf(" Chemain possible dans l'arbe est : \n");
  for( i = 0; v > 0; i++)
  {
    tab[i] = v%2;
    v /= 2;
  }
  if( i < a)
  {
    l = a - i;
    for (int j = 0; j < l; j ++)
      printf("0 ");
  }
  
  
  for( i = i -1; i >= 0; i--)
  {
    printf("%d ",tab[i]);   
  }
  printf("\n");
}
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
}

void eval (int a, int m, int **poid, int **value)
{
  int v = 0;
  int vv, z, p;
  int y = 0;
  int x = 2;

  for(int i = 0; i < a; i++)
    x*=2;

  int *cd = malloc(sizeof(int) * x);

  for(int i = 0; i < x; i++)
  {
    p = poid[a - 1][i];
    if(p <= m)
    {
      cd[y] = i;
      y += 1;
    }
  }

  for(int i = 0; i < y; i++)
  {
    z = cd[i];
    vv = value[a-1][z];
    if (vv > 10000 || vv < -10000)
      continue;
    if (v < vv)
    {
      v = vv;
    }
  }

  for(int i = 0; i < x; i++)
  {
    if(v == value[a-1][i])
    {
      printf("La solution optimaale a pour valeur : %d \n",v);
      bin(a, i);
    }
  }

  free(cd);
  
}
