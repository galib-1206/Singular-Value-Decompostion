#include "header.h"
void print_matrix(double res[][N], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
