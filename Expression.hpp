/*
---------------------------------------------------------
Project:    Convert Notations
Author:     Nethanya Dhaiphule
Language:   C++
Description:
    Validates and converts infix notations to postfix
---------------------------------------------------------
*/
#include "Stack.hpp"
#include <iostream>
#include <cctype>

class Expression
{
private:
    std::string inputExpression;
    Stack operatorStack;
    Stack outputStack;

    // General Methods
    bool isSpace(char c)
    {
        return isspace(c);
    }

    bool isOperator(char c)
    {
        // Used for Convert to check if value is operand
        // Return true if it is an operand
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            return true;
        }
        return false;
    }

    bool isOperand(char c)
    {
        return isdigit(c);
    }

    bool isOpenParenthesis(char c)
    {
        return c == '(';
    }

    bool isCloseParenthesis(char c)
    {
        return c == ')';
    }

    bool isMultiDigit(int i)
    {
        if (i - 1 > -1)
        {
            if (!(isSpace(inputExpression[i - 1])))
            {
                return true;
            }
        }
        return false;
    }

    // Validate Methods
    bool noStartEndOperator()
    {
        // Used for Validate to check if expression starts or ends with operator
        if (isOperator(inputExpression[0]) || isOperator(inputExpression[inputExpression.length() - 1]))
        {
            return false;
        }
        return true;
    }

    bool checkBalance()
    {
        Stack paranthesis;
        for (char c : inputExpression)
        {
            if (isOpenParenthesis(c))
            {
                paranthesis.push(c);
            }
            else if (isCloseParenthesis(c))
            {
                if (paranthesis.checkEmpty())
                {
                    return false; // closing parantheses without matching opening parantheses
                }
                paranthesis.pop();
            }
        }
        return paranthesis.checkEmpty(); // true if all opened are closed
    }

    bool validOrder()
    {
        // Used for Validate to check order of operands and operators
        // Return true if valid order

        bool x = false;
        for (int i = 0; i < inputExpression.length(); i++)
        {
            char c = inputExpression[i];

            if (isSpace(c) || isOpenParenthesis(c) || isCloseParenthesis(c))
            {
                continue; // skip
            }

            if (isOperand(c) && x == false)
            {
                x = true;
            }
            else if (isOperand(c) && x == true)
            {
                if (isMultiDigit(i))
                {
                    x = true;
                }
                else
                {
                    return false;
                }
            }
            else if (isOperator(c) && x == true)
            {
                x = false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    // Convert Methods
    int assignPriority(char c)
    {
        std::cout << "Entered this function with this character: " << c << "\n";
        switch (c)
        {
        case '*':
            return 2;
            break;

        case '/':
            return 2;
            break;

        case '+':
            return 1;
            break;

        case '-':
            return 1;
            break;

        default:
            return -1;
            break;
        }
        return -1;
    }

    bool isLowerEqualPriority(char c)
    {
        // Used for Convert to check precendence
        // Return true if priority of current operator is equal or lower priority than most recent pushed operator
        if (!operatorStack.checkEmpty() &&  !(isOpenParenthesis(operatorStack.peek())) && !(isCloseParenthesis(operatorStack.peek())))
        {
            if (assignPriority(c) <= assignPriority(operatorStack.peek()))
            {
                return true;
            }
        }
        
        return false;
    }

    bool closeBracket(char c)
    {
        // Used to check if current element of expression is a closed bracket
        //  Return true if it is
        if (isCloseParenthesis(c))
        {
            return true;
        }
        return false;
    }

    void numberRule(char c)
    {
        // Used to check if element is number and pushes element in Output Stack
        if (isOperand(c))
        {
            outputStack.push(c);
            return;
        }
    }

    void operatorRule(char c)
    {
        if (isOperator(c))
        {
            if (isLowerEqualPriority(c))
            {
                // We pop what is already in operator stack and push into output stack and push new operator into operator stack
                char temp = operatorStack.pop();
                operatorStack.push(c);
                outputStack.push(temp);
                return;
            }
            else
            {
                // if the current operator is of higher priority than what is already in the stack we simply push current operator into operator stack
                operatorStack.push(c);
                return;
            }
        }
    }

    void parenthesisRule(char c)
    {
        if (isOpenParenthesis(c))
        {
            operatorStack.push(c);
            return;
        }

        if (isCloseParenthesis(c))
        {
            // pop from operatorStack and push into outputStack until open paranthesis
            // Until the element we pop is a open paranthesis keep popping out of operatorStack and push into outputStack
            while (!(isOpenParenthesis(operatorStack.peek())))
            {
                outputStack.push(operatorStack.pop());
            }
            if (isOpenParenthesis(operatorStack.peek()))
            {
                operatorStack.pop();
            }
            return;
        }
    }

    void shouldOutput(char c)
    {
        numberRule(c);

        operatorRule(c);

        parenthesisRule(c);
    }

public:
    Expression()
    {
        // Constructor
    }

    void Input()
    {
        std::cout << "Please enter a infix expression: \n";
        std::getline(std::cin, inputExpression);
        // std::cout << inputExpression;
    }

    bool Validate()
    {
        if (noStartEndOperator() && checkBalance() && validOrder())
        {
            return true;
        }
        return false;
    }

    void Convert()
    {
        for (int i = 0; i < inputExpression.length(); i++) // Goes through every element of the string
        {
            char c = inputExpression[i]; // Checks every character
            shouldOutput(c);
        }

        while (!operatorStack.checkEmpty())
        {
            outputStack.push(operatorStack.pop());
        }

        outputStack.printStack();
    }
};