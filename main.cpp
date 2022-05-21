#include "source/Matrix.h"
#include "source/Gauss.h"
#include <cmath>

bool precision(double epsilon, std::vector<double>& prev, std::vector<double>& curr){
    double sum = 0;
    for(int i = 0; i < curr.size(); i++){
        sum += sqrt(pow((prev[i] - curr[i])/curr[i], 2));
    }
    return sum <= 0.001;
}




int main(){
    Matrix a(3, 4);
    std::cin >> a;
    std::cout << a;
    std::vector<double>prev;
    std::vector<double>curr;
    for (int i = 0; i < a.get_m(); i++){
        curr.push_back(a.data[i][a.get_m()] / a.data[i][i]);
    }
    bool check = false;
    while (!precision(0.01, prev, curr)){
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

    Gauss(a);
    std::cout << std::endl << a << std::endl;
    for (double i : curr){
        std::cout <<  i << "\t";
    }
    return 0;
}

