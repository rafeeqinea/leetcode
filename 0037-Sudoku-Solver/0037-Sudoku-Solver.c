#include <stdbool.h>

// Function to check if a number can be placed at board[row][col]
bool isValid(char** board, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
    {
        // Check if the number already exists in the same row
        if (board[row][i] == num)
            return false;

        // Check if the number already exists in the same column
        if (board[i][col] == num)
            return false;

        // Check if the number already exists in the same 3x3 box
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;  // ✅ FIXED: you had a colon ':' instead of semicolon ';'

        if (board[boxRow][boxCol] == num)
            return false;
    }
    return true;
}

// Recursive backtracking function to solve the board
bool backtrack(char** board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isValid(board, row, col, num))
                    {
                        board[row][col] = num;

                        if (backtrack(board))
                            return true;

                        // backtrack if stuck
                        board[row][col] = '.';
                    }
                }
                return false;  // No valid number found
            }
        }
    }
    return true;  // Fully solved
}

// Main entry point for LeetCode
void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    backtrack(board);
}

