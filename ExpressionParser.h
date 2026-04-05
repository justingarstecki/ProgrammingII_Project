#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <string>
#include "Calculator.h"

class ExpressionParser {
private:
    std::string expression;

public:
    void setExpression(std::string expr) { expression = expr; }
    double evaluateExpression();
};

#endif
