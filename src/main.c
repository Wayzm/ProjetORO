#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
  int check = 2;
  char str[1024];
  FILE* f;
  f = fopen("data.csv", "r");
  int a = atoi(argv[1]);
  int * matrix = malloc(sizeof(int) * a * a);
  
  int l = 0;
  while(check != EOF)
    {
       switch(check)
       {
          case ',':
            break;
          default:
            matrix[l] = check;
            l++;
            break;
       }
      check = fgetc(f);
    }

  free(matrix);
  return 0;
  
}
