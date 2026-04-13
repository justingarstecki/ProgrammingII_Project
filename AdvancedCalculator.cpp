#include "AdvancedCalculator.h"
#include <cmath>
#include <stdexcept>

double AdvancedCalculator::sine(double value) {
    return sin(value);
}

double AdvancedCalculator::cosine(double value) {
    return cos(value);
}

double AdvancedCalculator::logarithm(double value) {
    if (value <= 0) {
        throw std::runtime_error("Logarithm undefined for zero or negative values");
    }
    return log(value);
}

double AdvancedCalculator::squareRoot(double value) {
    if (value < 0) {
        throw std::runtime_error("Square root undefined for negative values");
    }
    return sqrt(value);
}
