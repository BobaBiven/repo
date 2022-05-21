//
// Created by askar on 21.05.22.
//

#include "GaussSeidel.h"
bool precision(double epsilon, std::vector<double>& prev, std::vector<double>& curr){
    double sum = 0;
    for(int i = 0; i < curr.size(); i++){
        sum += sqrt(pow((prev[i] - curr[i])/curr[i], 2));
    }
    return sum <= 0.001;
}

std::vector<double> GaussSeidel(Matrix &a, double epsilon){
    std::vector<double>prev;
    std::vector<double>curr;
    for (int i = 0; i < a.get_m(); i++){
        curr.push_back(a.data[i][a.get_m()] / a.data[i][i]);
    }
    bool check = false;
    while (!precision(epsilon, prev, curr)){
        prev = curr;
        double s1, s2;
        for(int i = 0; i < a.get_m(); i++) {
            s1 = 0, s2 = 0;
            for (int j = 0; j < i; i++){
                s1 += a.data[i][j] * curr[j];
            }
            for (int j = i + 1; j < a.get_m(); j++){
                s2 += a.data[i][j] * curr[j];
            }
            curr[i] = (*a.data[i].end() - s1 - s2) / a.data[i][i];
        }
    }
}
