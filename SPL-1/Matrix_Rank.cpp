#include "header.h"

void display(double mat[N][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%lf\t", mat[i][j]);
        printf("\n");
    }
}

// function for exchanging two rows of a matrix

void swap (double mat[N][N], int row1, int row2,
           int col)
{
    for (int i = 0; i < col; i++)
    {
        int temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

//void display(double mat[N][N], int row, int col);

// function for finding rank of matrix
int rankOfMatrix(double mat[N][N])
{
    int rank = N;

    for (int row = 0; row < rank; row++)
    {
        // while row traversing  sure that mat[row][0],....mat[row][row-1] are 0
        // Diagonal element is not zero
        if (mat[row][row])
        {
            for (int col = 0; col < N; col++)
            {
                if (col != row)
                {
                    //  All entries of current column as 0

                    double mult = (double)mat[col][row] / mat[row][row];
                    for (int i = 0; i < rank; i++)
                        mat[col][i] -= mult * mat[row][i];
                }
            }
        }

        // If Diagonal element is already zero.

        else
        {
            bool flag = true;

            // Find the non-zero element in current  column

            for (int i = row + 1; i < N; i++)
            {

                if (mat[i][row])
                {
                    swap(mat, row, i, rank);
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                // Reduce number of columns
                rank--;

                // Copy the last column here
                for (int i = 0; i < N; i++)
                    mat[i][row] = mat[i][rank];
            }

            // Process this row again
            row--;
        }

    }
    return rank;
}

