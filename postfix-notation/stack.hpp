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

class stack
{
private:
    int array[100]; // this is our stack
    int top;        // stores the index of top of stack

public:
    stack() // Constructor
    {
        top = -1;
    }

    bool checkEmpty()
    {
        if (top < 0)
        {
            return true;
        }
        return false;
    }

    void push(int value)
    {
        top++;
        array[top] = value;
    }

    int pop()
    {
        top--;
        return array[top + 1];
    }

    void printEquation()
    {
        std::cout << "\n";
        if (checkEmpty())
        {
            return;
        }
        // Prints Contents of Stack 
        for (int i = 0; i <= top; i++)
        {
            std::cout << array[i];
            std::cout << " ";
        }
    }

    int size()
    {
        return top + 1;
    }
};
