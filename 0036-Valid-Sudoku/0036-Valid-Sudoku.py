class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        rows = [set() for _ in range(9)]      # Track numbers in each row
        cols = [set() for _ in range(9)]      # Track numbers in each column
        boxes = [set() for _ in range(9)]     # Track numbers in each 3x3 box

        for i in range(9):                    # Loop over each row
            for j in range(9):                # Loop over each column
                val = board[i][j]             # Get the value at that cell

                if val == '.':                # If the cell is empty, skip
                    continue

                box_index = (i // 3) * 3 + (j // 3)  # Box number (0 to 8)

                if (val in rows[i] or         # Already seen in current row?
                    val in cols[j] or         # Already seen in current col?
                    val in boxes[box_index]): # Already seen in current box?
                    return False              # Invalid if duplicate

                rows[i].add(val)              # Mark number as seen in row
                cols[j].add(val)              # Mark number as seen in column
                boxes[box_index].add(val)     # Mark number as seen in box

        return True                           # If all good, it's valid

