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

void row_op(int n, int *matrix, int a, int *v)
{
  int min, max;
  if (n == 0)
  {
    min = INT_MAX;
    for (int i = 0; i < a; i ++)
    {
      for (int j = 0; j < a; j++)
      {
        if (i == j)
          continue;

        if (min > matrix[i*a +j])
          min = matrix[i*a +j];
      }
      
      for(int j = 0; j < a; j++)
      {
        if (i == j)
          continue;
        else
          matrix[i*a +j] -= min;
      }
      *v += min;
      min = INT_MAX;
    }
  }
  else 
  {
    printf("To be implemented. \n");
    exit(0);
  }
}

void col_op(int n, int *matrix, int a, int *v)
{
  int min, max;
  if (n == 0)
  {
    min = INT_MAX;
    for (int i = 0; i < a; i ++)
    {
      for (int j = 0; j < a; j++)
      {
        if (i == j)
          continue;

        if (min > matrix[i +j*a])
          min = matrix[i +j*a];
      }
      
      for(int j = 0; j < a; j++)
      {
        if (i == j)
          continue;
        else
          matrix[i +j*a] -= min;
      }
      *v += min;
      min = INT_MAX;
    }
  }
  else 
  {
    printf("To be implemented. \n");
    exit(0);
  }
}

void tree_building(int a, int b, int* matrix, int* v_r, 
                    int *v_c, int *n_sie, int* node)
{
  row_op(b, matrix, a, &v_r);
  col_op(b, matrix, a,&v_c);

  node[n_size] = v_r + v_c;
  *v_r = 0;
  *v_c = 0;
  *n_size ++;
}

void mat_reg (int a, int b, int *matrix, int *n_exclus, int *v_r
              int *v_c)
{
  int min_r, min_c, maxn m_reg;
  int k = 0;
  int l = 0;
  int **z_tab = malloc(sizeof(int)  * a);
  
  min_r = INT_MAX;
  min_c = INT_MAX;
  if( b == 0)
  {
    for(int i = 0; i < a ; i++)
    {
      for (int j = 0; j < a; j++)
      {
        if (i == j)
          continue;
      
        if(matrix[i * a + j] == 0)
        {
          z_tab[l][k] = j;
          k++;
          if (k > 1)
            min_r = 0;
        }
        else if (min > matrix[i * a + j])
        {
          min_r = matrix[ i * a + j];
        }
      }

      for( int j = 0; j < k; j ++)
      {
        for (int h = 0; h < a; h++)
        {
          if( h == j)
            continue;

          if(min_c > matrix[h ])
        }
      }
    }

    min = INT_MAX;
    for(int i = 0; i < a ; i++)
    {
      for (int j = 0; j < a; j++)
      {
        if (i == j)
          continue;
      
        if(matrix[i * a + j] == 0)
        {
          z_tab[k] = j;
          k++;
          if (k > 1)
            min = 0;
        }
        else if (min > matrix[i * a + j])
        {
          min = matrix[ i * a + j];
        }
      }

      for( int j = 0; j < k; j ++)
      {
        matrix[i * a + z_tab[j] ] += min;
      }

      min = INT_MAX;
    }
  }

  free(z_tab);
}
