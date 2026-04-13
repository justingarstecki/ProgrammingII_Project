#include "Calculator.h"
#include <stdexcept>

//Basic arithmetic operations
double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: Division by zero is not allowed.");
    }
    return a / b;
}
