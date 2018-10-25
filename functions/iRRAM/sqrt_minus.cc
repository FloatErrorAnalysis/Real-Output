#include "iRRAM.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace iRRAM;


const double begin_x = 0.0;
const double gap = 10;
const double end_x = 10e40;

REAL sqrt_minus(double x) {
    if(x + 1 < 0) {
        return REAL(-111111111);
    }
    return REAL(sqrt(x + 1) - sqrt(x));
}

void compute() {
    orstream myfile("/Users/py/GitHub/Real-Output/dataset/sqrt_minus.csv", std::ios::out);
    myfile << "x" << ","<< "y" << std::endl;
    int i;
    for(i = begin_x; i <= end_x; i+=gap) {
        myfile << i << "," << sqrt_minus(i) << std::endl;
    }
    cout << "Write end..." << std::endl;
}