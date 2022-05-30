#include "header.h"
//Calculating SD of main matrix
double SD(double original_matrix[][N], int r, int c)
{
    double sum=0,sd=0;
    double avg;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum+=(original_matrix[i][j]);
        }
    }
    avg=sum/(r*c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sd+=pow((original_matrix[i][j])-avg, 2);
        }
    }
    sd=sd/(r*c);

return sqrt(sd);

}
