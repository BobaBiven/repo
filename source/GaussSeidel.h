//
// Created by askar on 21.05.22.
//

#ifndef CASUAL_GAUSSSEIDEL_H
#define CASUAL_GAUSSSEIDEL_H

#include <vector>
#include "Matrix.h"
#include <cmath>


bool precision(double epsilon, std::vector<double>& prev, std::vector<double>& curr);
std::vector<double> GaussSeidel(Matrix &a, double epsilon);


#endif //CASUAL_GAUSSSEIDEL_H
