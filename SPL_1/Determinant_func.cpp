#include "header.h"
double Determinant_func(double original_matrix [][N],int row,int col)
{
        double Det =0;

        if(col==1) return original_matrix[0][0];
        else if(col==2) return ((original_matrix[0][0]*original_matrix[1][1])-(original_matrix[0][1]*original_matrix[1][0]));

        double sub_matrix[N][N] ={};
        int sign=1;
       for(int i=0;i<col;i++)
       {
           Sub_matrix_create(original_matrix,sub_matrix,row,col, 0, i);  // 0 as remove row,i as remove col.

            Det+=(sign*original_matrix[0][i]*Determinant_func(sub_matrix,row-1,col-1));
            sign=-sign;
           }
    return Det;
}

