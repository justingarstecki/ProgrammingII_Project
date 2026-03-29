#include "AdvancedCalculator.h"
#include <cmath>

//Advanced math functions
double AdvancedCalculator::sine(double value) {
    return sin(value);
}

double AdvancedCalculator::cosine(double value) {
    return cos(value);
}

double AdvancedCalculator::logarithm(double value) {
    if (value <= 0) {
        return 0; //error handling for log
    }
    return log(value);
}

double AdvancedCalculator::squareRoot(double value) {
    if (value < 0) {
        return 0; //error handling for negative numbers
    }
    return sqrt(value);
}
