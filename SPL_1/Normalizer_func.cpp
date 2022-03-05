#include "header.h"
//Calculating SD of main matrix
double SD(double original_matrix[][100], int r, int c)
{
    double add=0, avg, sd=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            add+=(original_matrix[i][j]);
        }
    }

    avg=add/(r*c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sd+=pow((original_matrix[i][j])-avg, 2);
        }
    }
    sd=sd/(r*c);

return sqrt(sd);

}
