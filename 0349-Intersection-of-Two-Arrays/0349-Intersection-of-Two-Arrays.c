#include <stdlib.h>  // for malloc

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int seen[1001] = {0};   // mark numbers in nums1
    int used[1001] = {0};   // to avoid adding duplicates
    int* result = (int*)malloc(sizeof(int) * 1001);  // max size, to be safe
    int i;
    int size = 0;

    // Mark nums1 values
    i = 0;
    while (i < nums1Size)
    {
        seen[nums1[i]] = 1;
        i++;
    }

    // Check nums2 values
    i = 0;
    while (i < nums2Size)
    {
        int val = nums2[i];
        if (seen[val] == 1 && used[val] == 0)
        {
            result[size] = val;
            size++;
            used[val] = 1;  // avoid duplicates
        }
        i++;
    }

    *returnSize = size;
    return result;
}

