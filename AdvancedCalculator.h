#ifndef ADVANCEDCALCULATOR_H
#define ADVANCEDCALCULATOR_H

#include "Calculator.h"
#include <cmath>
#include <stdexcept>

class AdvancedCalculator : public Calculator {
public:
    // Override base class functions
    double add(double a, double b) override;
    double subtract(double a, double b) override;
    double multiply(double a, double b) override;
    double divide(double a, double b) override;

    // Advanced functions
    double sine(double value);
    double cosine(double value);
    double logarithm(double value);
    double squareRoot(double value);
};

#endif
