#include "ExpressionParser.h"
#include "AdvancedCalculator.h"
#include <sstream>
#include <stdexcept>

void ExpressionParser::setExpression(const std::string& expr)
{
    expression = expr;
}

double ExpressionParser::evaluateExpression()
{
    std::istringstream iss(expression);
    AdvancedCalculator calc;

    double result;
    if (!(iss >> result))
    {
        throw std::runtime_error("Invalid expression");
    }

    char op;
    double num;

    while (iss >> op >> num)
    {
        if (op == '+')
        {
            result = calc.add(result, num);
        }
        else if (op == '-')
        {
            result = calc.subtract(result, num);
        }
        else if (op == '*')
        {
            result = calc.multiply(result, num);
        }
        else if (op == '/')
        {
            result = calc.divide(result, num);
        }
        else
        {
            throw std::runtime_error("Invalid operator");
        }
    }

    return result;
}
