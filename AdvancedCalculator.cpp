#include "AdvancedCalculator.h"
#include <cmath>
#include <stdexcept>

// Basic operations
double AdvancedCalculator::add(double a, double b) {
    return a + b;
}

double AdvancedCalculator::subtract(double a, double b) {
    return a - b;
}

double AdvancedCalculator::multiply(double a, double b) {
    return a * b;
}

double AdvancedCalculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: Division by zero is not allowed.");
    }
    return a / b;
}

// Advanced functions
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
