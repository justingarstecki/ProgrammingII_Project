#include "ExpressionParser.h"
#include "AdvancedCalculator.h"
#include <sstream>
#include <stdexcept>

double ExpressionParser::evaluateExpression() {
    double a, b;
    char op;

    std::istringstream iss(expression);

    // Validate input format
    if (!(iss >> a >> op >> b)) {
        throw std::runtime_error("Invalid expression format. Use: number operator number");
    }

    // Use AdvancedCalculator so project shows full OOP structure
    AdvancedCalculator calc;

    switch (op) {
        case '+':
            return calc.add(a, b);

        case '-':
            return calc.subtract(a, b);

        case '*':
            return calc.multiply(a, b);

        case '/':
            return calc.divide(a, b);

        default:
            throw std::runtime_error("Invalid operator. Use +, -, *, or /");
    }
}
