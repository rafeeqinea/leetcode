#include <stdbool.h>  // For using bool type
#include <stdlib.h>   // For malloc and free

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Step 1: Create markers for which rows/cols to zero
    bool* zero_rows = (bool*)calloc(rows, sizeof(bool));  // all false (0)
    bool* zero_cols = (bool*)calloc(cols, sizeof(bool));  // all false (0)

    // Step 2: Scan matrix and mark rows and cols
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zero_rows[i] = true;  // mark this row
                zero_cols[j] = true;  // mark this col
            }
        }
    }

    // Step 3: Second pass — update the matrix in-place
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (zero_rows[i] || zero_cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 4: Free memory
    free(zero_rows);
    free(zero_cols);
}

