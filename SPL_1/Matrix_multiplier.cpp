#include "header.h"

void Multiply(double matrix_p1[][N], double matrix_p2[][N], double res[][N], int r1, int c, int c2)
{
    int c1=c, r2=c;

    for(int i=0; i<r1; i++)
        {
        for(int j=0; j<=c2; j++)
        {
            for(int k=0; k<r2; k++)
            {
                res[i][j]+=(matrix_p1[i][k]*matrix_p2[k][j]);
            }
        }
    }
}
