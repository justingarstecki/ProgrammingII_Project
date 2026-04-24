#include "BasicCalculator.h"

double BasicCalculator::add(double a, double b) {
    return a + b;
}

double BasicCalculator::subtract(double a, double b) {
    return a - b;
}

double BasicCalculator::multiply(double a, double b) {
    return a * b;
}

double BasicCalculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: Division by zero is not allowed.");
    }
    return a / b;
}
