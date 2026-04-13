#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <string>
#include "Calculator.h"

class ExpressionParser {
private:
    std::string expression;

public:
    void setExpression(const std::string& expr);
    double evaluateExpression();
};

#endif
