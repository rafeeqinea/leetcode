class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None. Do not return anything, modify matrix in-place.
        """
        rows = len(matrix)
        cols = len(matrix[0])

        zero_rows = set()  # store row indices that need to be zero
        zero_cols = set()  # store col indices that need to be zero

        # Step 1: Identify rows and cols to be zeroed
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    zero_rows.add(i)
                    zero_cols.add(j)

        # Step 2: Set the cells to zero
        for i in range(rows):
            for j in range(cols):
                if i in zero_rows or j in zero_cols:
                    matrix[i][j] = 0

