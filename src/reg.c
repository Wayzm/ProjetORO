#include "reg.h"


void p_mat (int *matrix, int a)
{
  for(int i = 0; i < a; i ++ )
  {
    for(int j = 0; j < a; j++)
    {
      printf("%d ", matrix[i*5 +j]);
    }
    printf("\n");
  }
}


void Branch_and_Bound (int * matrix)
{

}

