#include <iostream>
#include "stack.hpp"
#include <sstream>

class reverseString
{
    stack newStack;

private:
    std::string input;

    void split()
    {
        std::stringstream split(input);
        std::string word;

        while (split >> word)
        {
            newStack.push(word);
        }
    }

public:
    reverseString()
    {
    }

    void getUserInput()
    {
        std::cout << "Please Enter Your Name \n";
        std::getline(std::cin, input);
        split();
    }
    void reverse()
    {
        while (!newStack.checkEmpty())
        {
            newStack.pop();
        }
    }
};
