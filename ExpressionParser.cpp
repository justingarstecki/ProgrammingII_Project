#include "ExpressionParser.h"
#include <sstream>

double ExpressionParser::evaluateExpression() {
    double result = 0;
    double a, b;
    char op;

    //Parsing for two numbers only
    std::istringstream iss(expression);
    iss >> a >> op >> b;

    //Use Calculator for the operation
    Calculator calc;
    if (op == '+') result = calc.add(a, b);
    else if (op == '-') result = calc.subtract(a, b);
    else if (op == '*') result = calc.multiply(a, b);
    else if (op == '/') result = calc.divide(a, b);

    return result;
}
