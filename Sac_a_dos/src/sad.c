/*** Chutzpa William YEUMO BARKWENDE ***/ 
/*** file that has the functions needed for the back experiement ***/ 

#include <stdio.h>
#include <stdlib.h>
#include "sad.h"

/*** This function gives us the path with how our branch is implemented ***/
/*** Each entry on the last layer of either 2D array cnly has one path upwards ***/
void bin(int a, int v, int u)
{
  int i;
  int l; 
  int tab[32];
  if(u == 0)
    printf("Chemain possible dans l'arbe est : \n");

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

// In this function we create our tree by branching the possibilities with our separation criteria
// we take the objet or not 
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

// First iteration of the branching
// Criteria : Take it or not
void init (int a, int *matrix, int **poid, int **value)
{
  poid[0][0] = matrix[0];
  poid[0][1] = 0;
  value[0][0] = matrix[a];
  value[0][1] = 0;
}

// Here we first look at which position on our poid aray fulfills the weight limit
// then we store this position in a temporary vector
// Then we look at which of these positions has the highest value
// Then we determine the path following the way upwards through a binary system since our criteria is binary
void eval (int a, int m, int **poid, int **value)
{
  int v = 0;
  int vv, z, p;
  int y = 0;
  int x = 2;

  for(int i = 1; i < a; i++)
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
    if (v < vv)
    {
      v = vv;
    }
  }

  printf("La solution optimaale a pour valeur : %d \n",v);
  p = m;
  for(int i = 0; i < x; i++)
  {
    if(v == value[a-1][i])
    {
      bin(a, i, 0);
      printf("Poids du sac : %d \n", poid[a-1][i]);
      if (p > poid[a-1][i])
      {
        vv = i;
        p = poid[a-1][i];
      }
    }

  }

  printf(" \nDonc le chemain optimal est : \n");
  bin(a, vv, 1);

  free(cd);
  
}
