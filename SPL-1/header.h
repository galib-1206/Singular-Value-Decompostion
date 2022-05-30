#include<bits/stdc++.h>
#include "constant.h"

using namespace std;


void print(double matrix_p1[][N], double matrix_p2[][N], int m, int k, int n);

double Rand_number();

void Multiply(double matrix_p1[][N], double matrix_p2[][N], double res[][N], int r1, int c, int c2);

double Determinant_func(double original_matrix [][N],int row,int col);

void Sub_matrix_create(double original_matrix[][N],double sub_matrix[][N], int row, int col,int r_row,int r_col);

double SD(double original_matrix[][N], int r, int c);

double eucledian_cost(double input[][N], double WH[][N], int row, int col);

void print_matrix(double res[][N], int m, int n);

int rankOfMatrix(double mat[N][N]);

void starting_method(double pass[], int total);

double SVD_func();

void transpose_func(double W[][N], double transpose_matrix[][N], int row, int col);
