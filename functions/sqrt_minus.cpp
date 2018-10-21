//
// Created by py on 2018/10/18.
//
#include "math.h"
#include <iostream>
#include <fstream>
using namespace std;
// sqrt(x + 1) - sqrt(x)
double sqrt_minus(double x) {
    return sqrt(x + 1) - sqrt(x);
}
bool is_zero(double x) {
    return sqrt_minus(x) != 0;
}

// Generate data from low bound to high bound, set initial gap as 1
double generate_data(double low_bound, double high_bound, double gap) {
    ofstream file;
    file.open("../dataset/double/sqrt_minus1.csv");
    file << "x,y\n";
    for(double i = low_bound; i <= high_bound && is_zero(i); i+=gap) {
        file << i << "," << sqrt_minus(i) << "\n";
    }
    file.close();
}

int main() {
    generate_data(0.0, 10e40, 10);
    return 0;
}