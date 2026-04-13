#include "ExpressionParser.h"
#include "AdvancedCalculator.h"
#include <sstream>
#include <stdexcept>

void ExpressionParser::setExpression(const std::string& expr) {
    expression = expr;
}

double ExpressionParser::evaluateExpression() {
    double a, b;
    char op;

    std::istringstream iss(expression);

    if (!(iss >> a >> op >> b)) {
        throw std::runtime_error("Invalid expression format. Use: number operator number");
    }

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
