#include "header.h"
//printing
void print(double matrix_p1[][100], double matrix_p2[][100], int m, int k, int n)
{  printf("Matrix_part1:\n");
       for (int i=0;i<m;i++)
    {
        for (int j=0;j<k;j++)
        {
            cout<<matrix_p1[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
     printf("Matrix_part2:\n");
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<matrix_p2[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

