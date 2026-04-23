#include "ExpressionParser.h"
#include "AdvancedCalculator.h"
#include <sstream>
#include <stdexcept>
#include <cctype>

void ExpressionParser::setExpression(const std::string& expr)
{
    expression = expr;
}

double ExpressionParser::evaluateExpression()
{
    AdvancedCalculator calc;
    size_t pos = 0;

    auto skipSpaces = [&]()
    {
        while (pos < expression.length() && isspace(expression[pos]))
        {
            pos++;
        }
    };

    auto parseNumber = [&]()
    {
        skipSpaces();

        size_t start = pos;
        bool hasDecimal = false;

        if (pos < expression.length() && expression[pos] == '-')
        {
            pos++;
        }

        while (pos < expression.length() && (isdigit(expression[pos]) || expression[pos] == '.'))
        {
            if (expression[pos] == '.')
            {
                if (hasDecimal)
                {
                    throw std::runtime_error("Invalid number");
                }
                hasDecimal = true;
            }

            pos++;
        }

        if (start == pos || (expression[start] == '-' && start + 1 == pos))
        {
            throw std::runtime_error("Invalid expression");
        }

        return std::stod(expression.substr(start, pos - start));
    };

    auto parseValue = [&]()
    {
        skipSpaces();

        if (expression.compare(pos, 4, "sqrt") == 0)
        {
            pos += 4;
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != '(')
            {
                throw std::runtime_error("Expected ( after sqrt");
            }

            pos++;
            double value = parseNumber();
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != ')')
            {
                throw std::runtime_error("Expected )");
            }

            pos++;
            return calc.squareRoot(value);
        }
        else if (expression.compare(pos, 3, "sin") == 0)
        {
            pos += 3;
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != '(')
            {
                throw std::runtime_error("Expected ( after sin");
            }

            pos++;
            double value = parseNumber();
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != ')')
            {
                throw std::runtime_error("Expected )");
            }

            pos++;
            return calc.sine(value);
        }
        else if (expression.compare(pos, 3, "cos") == 0)
        {
            pos += 3;
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != '(')
            {
                throw std::runtime_error("Expected ( after cos");
            }

            pos++;
            double value = parseNumber();
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != ')')
            {
                throw std::runtime_error("Expected )");
            }

            pos++;
            return calc.cosine(value);
        }
        else if (expression.compare(pos, 3, "log") == 0)
        {
            pos += 3;
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != '(')
            {
                throw std::runtime_error("Expected ( after log");
            }

            pos++;
            double value = parseNumber();
            skipSpaces();

            if (pos >= expression.length() || expression[pos] != ')')
            {
                throw std::runtime_error("Expected )");
            }

            pos++;
            return calc.logarithm(value);
        }

        return parseNumber();
    };

    double result = parseValue();

    while (pos < expression.length())
    {
        skipSpaces();

        if (pos >= expression.length())
        {
            break;
        }

        char op = expression[pos];
        pos++;

        double num = parseValue();

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
