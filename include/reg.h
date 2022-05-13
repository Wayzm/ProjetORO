#ifndef REG_H
#define REG_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void p_mat (int *matrix, int a);

void row_op(int b , int* matrix, int a, int *v, int max);
void col_op(int b , int* matrix, int a, int *v, int max);

void tree_building(int a, int b, int* matrix, int *v_r,
                  int *v_c, int *n_size, int *node, int max);
void tree_update(int *node, int *n_exclus, int n_size);

void mat_reg(int a, int b, int *matrix, int *n_exclus, int *n_size,
            int *e_r, int *e_c, int max);
void mat_cut(int a, int *matrix, int e_r, int e_c);
#endif // !REG_H

