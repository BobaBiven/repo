//
// Created by askar on 20.05.22.
//

#include "Gauss.h"
void Gauss(Matrix &a){
    for (int i = 0; i < a.get_m(); i++){
        if (a.data[i][i] != 0){
            double tmp1 = a.data[i][i];
            for (int j = i; j < a.get_n(); j++) {
                a.data[i][j] = a.data[i][j] / tmp1;
            }
            for (int k = 0; k < a.get_m(); k++) {
                if (k != i) {
                    if (a.data[k][i] != 0) {
                        double tmp2 = a.data[k][i];
                        for (int l = i; l < a.get_n(); l++) {
                            a.data[k][l] = a.data[k][l] - tmp2 * a.data[i][l];
                        }
                    }
                }
            }
        }
    }
}