#include<bits/stdc++.h>
using namespace std;

#define e 2.72828
#define sigma 4.0
#define mu 10.0
#define initial (0.398922804/sigma)

//Initialization of matrices using random number
double randfrom(double minn, double maxx)
{
    double range = (maxx - minn);
    double div = RAND_MAX / range;
    return minn + (rand() / div);
}
double exponential(){ // e^(-0.5*x^2)
    double standard_val,power, x;
    x=randfrom(-9.0,10.0);
    standard_val=((x-sigma)/mu);
    power=pow(standard_val, 2);
    return pow(e, -0.5*power);
}
double Rand_number(){
    return initial*exponential();
}
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
int main()
{
   int original_matrix [100] [100]={};
   int row,col,i,j,k;
   printf("Enter number of rows and cols:");
   cin>>row>>col;
printf("Input Matrix:\n ");
     for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            cin>>original_matrix[i][j];
    }
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
}



