/*
---------------------------------------------------------
Project:    Post Fix Notation
Author:     Nethanya Dhaiphule
Language:   C++
Description:
    Validates and solves a postfix notation using 
    stack data structure

---------------------------------------------------------
*/
#include <iostream>

class operation
{
public:
    int answer;
    operation() // Constructor
    {
        answer = 0;
    }

    int simplify(int value1, int value2, char operandInput)
    {
        switch (operandInput)
        {
        case '+':
            return answer = value1 + value2;           
            break;
        case '-':
           return answer = value1 - value2;
            break;
        case '*':
            return answer = value1 * value2;
            break;
        case '/':
            if (value2 != 0)
            {
                return answer = value1 / value2;
                break;
            }
            else
            {
                std::cout << "Error: Cannot Divide 0.";
                break;
            }
        default:
            std::cout << "Unsupported operator.\n";
            break;
        }
        return -1;
    }
};
