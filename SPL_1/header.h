#include<bits/stdc++.h>
#include "constant.h"

using namespace std;


void print(double matrix_p1[][100], double matrix_p2[][100], int m, int k, int n);

double Rand_number();

void Multiply(double matrix_p1[][100], double matrix_p2[][100], double res[][100], int r1, int c, int c2);

double Determinant_func(double original_matrix [][100],int row,int col);

void Sub_matrix_create(double original_matrix[][100],double sub_matrix[][100], int row, int col,int r_row,int r_col);
double SD(double original_matrix[][100], int r, int c);
double eucledian_cost(double input[][100], double WH[][100], int row, int col);
void print_matrix(double res[][100], int m, int n);
