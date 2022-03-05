#include <iostream>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;

int main()
{
   double original_matrix [100] [100]={};
   int row,col,i,j,k;
   printf("Enter number of rows and cols:");
   cin>>row>>col;
printf("Input Matrix:\n ");
     for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            cin>>original_matrix[i][j];
    }
    cout<<Determinant_func(original_matrix, row, col)<<endl<<endl;

    cout<<"After normalization"<<endl;
     double sd=SD(original_matrix,row,col);

       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            original_matrix[i][j]/=sd;
        }
    }
     for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            cout<<" "<<original_matrix[i][j];
            cout<<endl;
    }


     //Generating two matrices using Rand number..

    //devided into two matrices
    printf(" Enter dimension: ");
    cin>>k; // k, col of part1 & row of part2

    double matrix_p1[100][100]={}, matrix_p2[100][100]={};

    for(i=0;i<row;i++){
        for(j=0;j<k;j++){
            matrix_p1[i][j]=Rand_number();
        }
    }

    for(i=0;i<k;i++){
        for(j=0;j<col;j++){
            matrix_p2[i][j]=Rand_number();
        }
    }
    print(matrix_p1, matrix_p2, row, k, col);
    double res[100][100]={0};

    double cost = eucledian_cost(res,original_matrix, row, col);

    cout<<"Cost: "<<cost<<endl;
}
