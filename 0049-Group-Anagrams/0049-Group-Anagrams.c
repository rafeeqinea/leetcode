#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper: Sort characters in a string
void sort_str(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        int j = i + 1;
        while (str[j] != '\0') {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
            j++;
        }
        i++;
    }
}

// Compare function for qsort (not used but can help in sort_str alternative)
int cmpstr(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Core function
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // Allocate result array (max groups = input size)
    char ***res = malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = malloc(sizeof(int) * strsSize);
    *returnSize = 0;

    // Allocate storage for keys (sorted strings)
    char *keys[strsSize];
    for (int i = 0; i < strsSize; i++) {
        keys[i] = strdup(strs[i]);
        sort_str(keys[i]);
    }

    // Track which strings are grouped
    bool used[strsSize];
    for (int i = 0; i < strsSize; i++) used[i] = false;

    for (int i = 0; i < strsSize; i++) {
        if (used[i]) continue;

        // Create new group
        res[*returnSize] = malloc(sizeof(char*) * strsSize);  // max possible
        int colSize = 0;

        for (int j = 0; j < strsSize; j++) {
            if (!used[j] && strcmp(keys[i], keys[j]) == 0) {
                res[*returnSize][colSize++] = strdup(strs[j]);
                used[j] = true;
            }
        }

        (*returnColumnSizes)[*returnSize] = colSize;
        (*returnSize)++;
    }

    return res;
}
