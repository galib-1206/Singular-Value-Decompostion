#include "header.h"
void Sub_matrix_create(double original_matrix[][N],double sub_matrix[][N], int row, int col,int r_row,int r_col) //remove_row ,remove_col as i
{
    int k=0,l=0;
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<col;j++)
        {
            if((i!=r_row)&&(j!=r_col))
            {
                sub_matrix[k][l]=original_matrix[i][j];
                l++;
            }
        }
        if(i!=r_row) k++;
        l=0;
    }
    cout<<row<<col<<endl;
    print_matrix(sub_matrix, row, col);
}
