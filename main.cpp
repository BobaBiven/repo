#include "source/Matrix.h"
#include "source/Gauss.h"
#include "source/GaussSeidel.h"
#include <cmath>
#include "source/Determinant.h"

int main(){
    Matrix a(2, 2);
    std::cin >> a;
    std::cout << a;
    //std::vector<double>tmp = GaussSeidel(a, 0.1);
    //Gauss(a);
    double k;
    k = Determinant(a);
    std::cout << std::endl << k << std::endl;
    return 0;
}

