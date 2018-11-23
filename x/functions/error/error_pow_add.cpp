//
// Created by xzh on 2018/10/29.
//
#include "cmath"
#include "iRRAM.h"

using namespace iRRAM;

/**
 * calculation with error
 * @param x input
 * @return result of pow
 */
double sqrt_minus_error(double x) {
    return (x * x - 1) + x * x;
}

/**
 * calculation without error
 * @param x input
 * @return result of pow
 */
REAL sqrt_minus_real(const REAL &x) {
    return REAL(x * x - 1) + REAL(x * x);
}

/**
 * Generate data from low bound to high bound, set initial gap as 1
 * @param low_bound low bound
 * @param high_bound high bound
 * @param gap interval
 * @param number the number of data to be generated
 */
void generate_data(double low_bound, double high_bound, double gap) {
    orstream file("../dataset/error_pow_add.csv", std::ios::out);
    file << "x,y\n";

    int number = static_cast<int>((high_bound - low_bound) / gap);

    double current_input = low_bound;
    for (int i = 0; i <= number; i++) {
        double result_error = sqrt_minus_error(current_input);
        REAL result_real = sqrt_minus_real(current_input);
        file << current_input << "," << abs((result_real - REAL(result_error)).as_double()) << "\n";
        current_input += gap;
    }
}

void compute() {
    generate_data(1, 10000, 0.1);
}