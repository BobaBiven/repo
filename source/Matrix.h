//
// Created by askar on 20.05.22.
//

#ifndef CASUAL_MATRIX_H
#define CASUAL_MATRIX_H
#include "iostream"
#include "vector"
class Matrix{
private:
    int size_m;
    int size_n;
public:
    //double **data;
    std::vector<std::vector<double>>data;


    Matrix(int m, int n);
    Matrix(const Matrix&a);
    ~Matrix();

    int get_m() const { return this->size_m; }

    int get_n() const { return this->size_n; }

    friend std::istream &operator>>(std::istream &is, Matrix &a);
    friend std::ostream &operator<<(std::ostream &os, Matrix &a);

    Matrix &operator=(Matrix const a) {
        this->size_m = a.get_m();
        this->size_n = a.get_n();
        for (int i = 0; i < a.get_m(); i++) {
            for (int j = 0; j < a.get_n(); j++) {
                this->data[i][j] = a.data[i][j];
            }
        }
        return *this;
    }
    friend Matrix operator-(Matrix &a, Matrix &b);
    friend Matrix operator+(Matrix &a, Matrix &b);
};



#endif //CASUAL_MATRIX_H

