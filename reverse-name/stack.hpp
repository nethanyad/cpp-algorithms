#include <iostream>

class stack
{
private:
    std::string array[100]; //this is our stack
    int top; // stores the index of top of stack

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

    void push(std::string word)
    {
        top++;
        array[top] = word;
    }

    void pop()
    {
        std::cout << array[top];  
        std::cout << " "; 
        top--;

    }
};