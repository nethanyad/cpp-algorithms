/*
---------------------------------------------------------
Project:    Sudoku Solver
Author:     Nethanya Dhaiphule
Language:   C++
Description:
    Solves a given 9x9 Sudoku puzzle. Validates each 
    move based on Sudoku rules for rows, columns, and 
    3x3 subgrids.
---------------------------------------------------------
*/

#include <iostream>

class Sudoku
{
private:
    int board[9][9];
    int numberToFind = 0;

    bool checkRows(int row, int counter)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == counter)
            {
                return false; // Same number was not found in row
            }
        }
        return true;
    }

    bool checkColumns(int column, int counter)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][column] == counter)
            {
                return false;
            }
        }
        return true;
    }

    bool checkBox(int row, int column, int counter)
    {
        int startingRow = (row / 3) * 3;
        int startingColumn = (column / 3) * 3;

        for (int i = startingRow; i < startingRow + 3; i++)
        {
            for (int j = startingColumn; j < startingColumn + 3; j++)
            {
                if (i == row && j == column)
                {
                    continue;
                }

                if (board[i][j] == counter)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void fullBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    numberToFind++;
                }
            }
        }
    }

public:
    Sudoku(int b[9][9]) // Constructor to initalize board
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = b[i][j];
            }
        }
    }

    bool solve()
    {
        fullBoard();
       // checkDuplicate();
         while (numberToFind != 0)
        {
             if (!checkDuplicate()) // No solution found in the cell means the Suduko is unsolvable.
             {
                return false;
            }
        }
        return true; // Puzzle Solved
    }

    bool checkDuplicate()
    {
       // int c = 1;
        for (int i = 0; i < 9; i++)
        {
             std::cout << "i = " << i; 
            for (int j = 0; j < 9; j++)
            {
                 std::cout << "j = " << j;
                 if (board[i][j] == 0)
                 {
                     int singlePossibleValue = 0; // Checks if there is already value stored in cell
                     int possibleValue = 0;       // Holds possible single value that could be in cell
                 
                     for (int counter = 1; counter < 10; counter++) // Goes through numbers 1 to 9
                     {
                         if (checkRows(i, counter) && checkColumns(j, counter) && checkBox(i, j, counter)) // value can be added
                         {
                             singlePossibleValue++;
                             possibleValue = counter;
                             if (singlePossibleValue > 1)
                                 break;
                         }
                     }

                     if (singlePossibleValue == 1)
                     {
                         board[i][j] = possibleValue;
                         numberToFind--;
                     }

                     if (singlePossibleValue == 0) // No solution found in the cell means the Suduko is unsolvable.
                     {
                         return false;
                     }
                 }
            }               
    }
    return true;
}

    void printBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    int board[9][9] = {
        {0, 0, 0, 0, 9, 0, 5, 0, 0},
        {0, 6, 4, 7, 0, 0, 9, 0, 1},
        {3, 0, 7, 8, 0, 0, 0, 0, 0},
        {0, 3, 6, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 6, 7, 0},
        {0, 0, 0, 0, 0, 8, 7, 0, 9},
        {7, 0, 9, 0, 0, 5, 4, 2, 0},
        {0, 0, 3, 0, 4, 0, 0, 0, 0}};

    Sudoku sudoku(board);

    if (sudoku.solve())
    {
        sudoku.printBoard();
    }
    else
    {
        std::cout << "Error, No Solution Found.\n";
    }
    return 0;
}

