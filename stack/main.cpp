/*
---------------------------------------------------------
Project:    Stack Data Structure
Author:     Nethanya
Language:   C++
Description:
    Implements a stack from scratch with push, pop, and
    peek operations. Demonstrates LIFO (Last-In, First-Out)
    behavior using arrays/pointers and basic memory handling.
---------------------------------------------------------
*/
#include "stack.hpp"
#include <stdexcept> // for std::runtime_error

int getChoice()
{
    int choice;
    std::cin >> choice;
    return choice;
}


void printMenu()
{
    std::cout << "Pick an Option:\n";
    std::cout << "1. Pop\n";
    std::cout << "2. Push\n";
    std::cout << "3. Print Stack \n";
    std::cout << "4. Print Number of Elements \n";
    std::cout << "5. Exit Program \n";
    std::cout << "Enter choice. \n ";
    std::cout << "------------------------------\n";
    
}

int main()
{
    stack Stack;
    bool runProgram = true;
    while (runProgram)
    {
        printMenu();
        bool loop = true;
        while (loop)
        {
            switch (getChoice())
            {
            case 1:
                Stack.pop();
                loop = false;
                break;
            case 2:
            {
                //int input = pushInput();
                Stack.push();
                loop = false;
                break;
            }
            case 3:
                Stack.printStack();
                loop = false;
                break;
             case 4:
                Stack.printElements();
                loop = false;
                break;
            case 5:
                loop = false;
                runProgram = false;
                break;
            default:
                std::cout << "Invalid choice: please enter valid number. \n";
                break;
            }
        }
    }
    return 0;

}
