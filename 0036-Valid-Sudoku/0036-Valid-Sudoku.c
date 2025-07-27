#include <stdbool.h> // for bool, true, false
#include <stdlib.h>  // for malloc

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    // Arrays to track digits seen in rows, columns, and boxes
    int rows[9][9] = {0};    // rows[i][digit] = 1 if seen
    int cols[9][9] = {0};    // cols[j][digit] = 1 if seen
    int boxes[9][9] = {0};   // boxes[box_index][digit] = 1 if seen

    // Loop through all cells
    for (int i = 0; i < 9; i++)          // row index
    {
        for (int j = 0; j < 9; j++)      // column index
        {
            char cell = board[i][j];    // current cell

            if (cell == '.')            // ignore empty cells
                continue;

            int num = cell - '1';       // convert '1'-'9' to 0-8 index

            // Calculate which 3x3 box this cell belongs to
            int box_index = (i / 3) * 3 + (j / 3);

            // Check if number already seen in row, column, or box
            if (rows[i][num] || cols[j][num] || boxes[box_index][num])
                return false;

            // Mark the number as seen
            rows[i][num] = 1;
            cols[j][num] = 1;
            boxes[box_index][num] = 1;
        }
    }

    return true; // No duplicates found
}

