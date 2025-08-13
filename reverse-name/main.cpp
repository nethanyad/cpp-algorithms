/*
---------------------------------------------------------
Project:    Reverse Name
Author:     Nethanya Dhaiphule
Language:   C++
Description:
      Reads a string from the user and outputs its reverse
      using a stack data structure.
---------------------------------------------------------
*/
#include "reverseString.hpp"

int main()
{
    reverseString rs;
    rs.getUserInput();       
    rs.reverse();
    return 0;

}
