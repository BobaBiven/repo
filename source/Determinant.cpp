//
// Created by askar on 21.05.22.
//

#include "Determinant.h"
double Matrix_minor(Matrix& a, int m, int n) {
    Matrix tmp(a);
    tmp.DeleteLine(m);
    tmp.DeleteColumn(n);
    double sum = 0;
    if (a.get_m() == 1){
        return a.data[0][0];
    }
    else{
        for(int i = 0; i < a.get_n(); i++){
            sum += tmp.data[0][i] * pow(-1, i) * Matrix_minor(tmp, i, i);
        }
    }
    return sum;
}

double Determinant(Matrix& a){
    double sum = 0;
    for (int i = 0; i < a.get_n(); i++){
        sum += a.data[0][i] * pow(-1, i) * Matrix_minor(a, i, i);
    }
    return sum;
}