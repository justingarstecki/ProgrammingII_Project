#ifndef ADVANCEDCALCULATOR_H
#define ADVANCEDCALCULATOR_H

#include "Calculator.h"
#include <cmath> // for math functions like sin, cos, sqrt, log

class AdvancedCalculator : public Calculator {
public:
    double sine(double value);
    double cosine(double value);
    double logarithm(double value);
    double squareRoot(double value);
};

#endif
