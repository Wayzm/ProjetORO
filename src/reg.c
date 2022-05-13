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

void row_op(int n, int *matrix, int a, int *v, int m)
{
  int min;
  min = m;
  if (n == 0)
  {
    min = m;
    for (int i = 0; i < a; i ++)
    {
      for (int j = 0; j < a; j++)
      {
        if (matrix[i * a + j] == -1)
          continue;

        if (min > matrix[i*a +j])
          min = matrix[i*a +j];
      }
      
      for(int j = 0; j < a; j++)
      {
        if (matrix[ i * a + j] == -1)
          continue;
        else
          matrix[i*a +j] -= min;
      }
      *v += min;
      min = m;
    }
  }
  else 
  {
    printf("To be implemented. \n");
    exit(0);
  }
}

void col_op(int n, int *matrix, int a, int *v, int m)
{
  int min;
  min = m;
  if (n == 0)
  {
    min = INT_MAX;
    for (int i = 0; i < a; i ++)
    {
      for (int j = 0; j < a; j++)
      {
        if (matrix[i + j * a] == -1)
          continue;

        if (min > matrix[i + j * a])
          min = matrix[i +j*a];
      }
      
      for(int j = 0; j < a; j++)
      {
        if (matrix[ i + j * a] == -1)
          continue;
        else
          matrix[i +j*a] -= min;
      }
      *v += min;
      min = m;
    }
  }
  else 
  {
    printf("To be implemented. \n");
    exit(0);
  }
}

void tree_building(int a, int b, int* matrix, int* v_r, 
                    int *v_c, int *n_size, int* node, int m)
{
  row_op(b, matrix, a, &v_r, m);
  col_op(b, matrix, a,&v_c, m);

  node[*n_size] = *v_r + *v_c;
  *v_r = 0;
  *v_c = 0;
  *n_size += 1;;
}

void mat_reg (int a, int b, int *matrix, int *n_exclus, int *n_size,
              int *e_r, int *e_c, int m)
{
  int min_r, min_c, max;
  int k = 0;
  int *z_tab[2];
  int v, u;

  // Keep trackof where the 0 are
  for(int i = 0; i < 2 ; i++)
    z_tab[i] = malloc(sizeof(int)  * a);
  
  min_r = m;
  min_c = m;
  max = 0;
  if( b == 0)
  {
    for(int i = 0; i < a ; i++)
    {
      for (int j = 0; j < a; j++)
      {
        if (matrix[i * a + j] == -1)
          continue;
      
        if(matrix[i * a + j] == 0)
        {
          k++;
          if (k > 1)
          {
            min_r = 0;
            break;
          }
        }
        else if (min_r > matrix[i * a + j])
        {
          min_r = matrix[ i * a + j];
        }
      }
      z_tab[0][i] = min_r;

      k = 0;
      for( int j = 0; j < a; j++)
      {
        if (matrix[i + j * a] == -1)
          continue;

        if (matrix [i + a * j] == 0)
        {
          k++;
          if (k > 1)
          {
            min_c = 0;
            break;
          }
        }

        else if(min_c > matrix[i + a * j])
        {
          min_c = matrix [i + a * j];
        }
      }
    k = 0;
    z_tab[1][i] = min_c;

    min_r = m;
    min_c = m;

    }
  
    for(int i = 0; i < a; i++)
    {
      for (int j = 0; j < a; j++)
      {
        if( matrix[i * a + j] == 0)
        {
          v = z_tab[0][i] + z_tab[1][j];
          if (max < v )
          {
            max = v;
            *e_r = i;
            *e_c = j;
          }
        }
      }
    }
    u = *n_size;
    n_exclus[u - 1] = max;


  }

  for(int i = 0; i< 2; i++)
    free(z_tab[i]);
  
}

void tree_update (int *node, int *n_exclus, int n_size)
{
  int u = n_size;
  node[u] = node[u - 1] + n_exclus[u -1];
}

void mat_cut (int a, int *matrix, int e_r, int e_c)
{
  for (int i = 0; i < a; i++)
  {
    matrix[ i * a + e_c] = -1;
    matrix[ e_r * a + i] = -1;
  }
}
