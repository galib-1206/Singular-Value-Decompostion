#include "header.h"
double eucledian_cost(double input[][100], double WH[][100], int row, int col)
{
    double cost = 0.0;
    double sum = 0.0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += pow((input[i][j] - WH[i][j]), 2);
        }
    }
    cost = sqrt(sum);

    return cost;
}

