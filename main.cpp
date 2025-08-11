/*
---------------------------------------------------------
Project:    Convert Notations
Author:     Nethanya Dhaiphule
Language:   C++
Description:
    Validates and converts infix notations to postfix
---------------------------------------------------------
*/
#include "Expression.hpp"

int main()
{
    Expression expression;
    expression.Input();
    if (expression.Validate())
    {
        std::cout << "Validation Successful! \n";
        expression.Convert();
    }
    else
    {
        std::cout << "Error: invalid infix format input";
    }

    return 0;
}