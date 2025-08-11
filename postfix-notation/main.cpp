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
#include "stack.hpp"
#include "operation.hpp"
#include <limits>

int operandInput;
char operatorInput;

void printMenu()
{
    std::cout << "\n";
    std::cout << "Pick an Option:\n";
    std::cout << "1. Enter an Operand\n";
    std::cout << "2. Enter an Operator\n";
    std::cout << "3. Display Current Equation \n";
    std::cout << "4. Exit Program \n";
    std::cout << "Enter choice. \n ";
    std::cout << "------------------------------\n";
}

int getChoice()
{
    int choice;
    std::cin >> choice;
    return choice;
}

bool isOperator()
{
    return operatorInput == '+' || operatorInput == '-' || operatorInput == '*' || operatorInput == '/';
}

int main()
{
    stack Stack;
    operation Operation;
    bool runProgram = true;
    while (runProgram)
    {
        printMenu();
        switch (getChoice())
        {
        case 1:
        {
            std::cout << "Enter operand. \n ";
            std::cin >> operandInput;
            Stack.push(operandInput);
            break;
        }
        case 2:
        {
            std::cout << "Enter operator. \n ";
            std::cin >> operatorInput;

            if (isOperator())
            {
                if (Stack.size() < 2)
                {
                    std::cout << "Error: Not enough operands in stack.\n";
                    break;
                }
                int value2 = Stack.pop();
                int value1 = Stack.pop();

                int answer = Operation.simplify(value1, value2, operatorInput);
                Stack.push(answer);
            }
            else
            {
                std::cout << "Error, please enter valid operator. \n";
            }
            break;
        }
        case 3:
            Stack.printEquation();
            break;
        case 4:
            runProgram = false;
            break;
        default:
            std::cout << "Invalid choice: please enter valid option. \n";
            break;
        }
    }
    return 0;
}
