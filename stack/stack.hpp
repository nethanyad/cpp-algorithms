#include <iostream>
#include <stdexcept> // for std::runtime_error
class stack
{
private:
    int array[10];
    int top; // stores the index of top of stack
    const int max = 10;

    bool checkFull()
    {
        if (top > 8)
        {
            std::cout << "Stack is Full!\n";
            std::cout << "\n";
            return true;
        }
        return false;
    }

    bool checkEmpty()
    {
        if (top < 0)
        {
            std::cout << "Stack is Empty!\n";
            return true;
        }
        return false;
    }

public:
    stack() // Constructor
    {
        top = -1;
    }

    void push()
    {
        // Push user input values into array
        if (checkFull())
        {

            return;
        }

        int input;
        std::cout << "Enter number to add into stack:\n";
        std::cin >> input;

        top++;
        array[top] = input;
        // std::cout << top;
    }

    void pop()
    {
        // Pop user input values out of array
        if (checkEmpty())
        {
            std::cout << "\n";
            return;
        }
        std::cout << array[top] << "\n";   
        std::cout << "\n";  
        top--;
    }

    void printStack()
    {
        std::cout << "\n";
        if (checkEmpty())
        {
            return;
        }
        // Prints Contents of Stack
        for (int i = top; i >= 0; i--)
        {
            std::cout << array[i];
            std::cout << "\n";
        }
    }

    void printElements()
    {
        std::cout << "Number of elements: " << top + 1 << "\n";
        std::cout << "\n";
    }
};