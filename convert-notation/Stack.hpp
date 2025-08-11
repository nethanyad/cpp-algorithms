/*
---------------------------------------------------------
Project:    Convert Notations
Author:     Nethanya Dhaiphule
Language:   C++
Description:
    Validates and converts infix notations to postfix
---------------------------------------------------------
*/
#include <iostream>

class Stack
{
private:
    char array[100];
    int top; // stores the index of top of stack

    bool checkFull()
    {
        if (top > 98)
        {
            return true;
        }
        return false;
    }

public:
    Stack() // Constructor
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

    void push(char c)
    {
        top++;
        array[top] = c;
    }

    char pop()
    { 
        if (checkEmpty())
        {
            return -1;
        }
        char returnValue = array[top];
        top--;
        return returnValue;
    }

    char peek()
    {
        if (checkEmpty())
        {
            return -1;
        }
        char returnValue = array[top];
        return returnValue;
    }

    void printStack()
    {
        if (checkEmpty())
        {
            return;
        }
        // Prints Contents of Stack
        for (int i = 0; i < top+1; i++)
        {
            std::cout << array[i];
            std::cout << " ";
        }
    }

    int returnTop()
    {
        return top;
    }
};
