#ifndef BASICALCULATOR_H
#define BASICALCULATOR_H

#include "Calculator.h"
#include <stdexcept>

class BasicCalculator : public Calculator {
public:
    double add(double a, double b) override;
    double subtract(double a, double b) override;
    double multiply(double a, double b) override;
    double divide(double a, double b) override;
};

#endif
