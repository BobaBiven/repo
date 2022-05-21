//
// Created by askar on 20.05.22.
//

#include "Matrix.h"
#include <iostream>


Matrix::Matrix(int m, int n) {
    size_m = m;
    size_n = n;
    data.resize(size_m);
    for (int i = 0; i < size_n; i++) {
        std::vector<double>tmp;
        tmp.resize(size_n);
        data.push_back(tmp);
    }
    for (int i = 0; i < size_m; i++) {
        for (int j = 0; j < size_n; j++) {
            data[i].push_back(0.0);
        }
    }
}

Matrix::Matrix(const Matrix&a) : size_m(a.get_m()), size_n(a.get_n()){ //конструктор копирования
    data.resize(size_m);
    for (int i = 0; i < size_n; i++) {
        std::vector<double>tmp;
        tmp.resize(size_n);
        data.push_back(tmp);
    }
    for (int i = 0; i < size_m; i++) {
        for (int j = 0; j < size_n; j++) {
            data[i].push_back(a.data[i][j]);
        }
    }


}

Matrix::~Matrix() {}


Matrix operator+(Matrix &a, Matrix &b)
{
    Matrix tmp(a.get_m(), a.get_n());
    for (int i = 0; i < a.get_m(); i++) {
        for (int j = 0; j < a.get_n(); j++) {
            tmp.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return(tmp);
}

Matrix operator-(Matrix &a, Matrix &b)
{
    Matrix tmp(a.get_m(), a.get_n());
    for (int i = 0; i < a.get_m(); i++) {
        for (int j = 0; j < a.get_n(); j++) {
            tmp.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return(tmp);
}


std::ostream &operator<<(std::ostream &os, Matrix &a) {
    for (int i = 0; i < a.get_m(); i++) {
        for (int j = 0; j < a.get_n(); j++) {
            std::cout << a.data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &a)
{
    for (int i = 0; i < a.get_m(); i++) {
        for (int j = 0; j < a.get_n(); j++) {
            std::cin >> a.data[i][j];
        }
    }
    return(is);
}

