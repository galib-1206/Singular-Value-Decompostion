#include "header.h"
void transpose_func(double W[][N], double transpose_matrix[][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            transpose_matrix[j][i] = W[i][j];
        }
    }
    //print_matrix(transpose_matrix, col, row);
}
