//SET MATRIX ZERO

void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        int firstRowValue = 1;
        for(int col = 0; col < cols; col++)
                if(matrix[0][col] == 0)
                        firstRowValue = 0;

        for(int row = 1; row < rows; row++)
                for(int col = 0; col < cols; col++)
                        if(matrix[row][col] == 0)
                                matrix[row][0] = matrix[0][col] = 0;

        for(int row = 1; row < rows; row++)
                for(int col = cols-1; col >= 0; col--)
                        if(matrix[row][0] == 0 or matrix[0][col] == 0)
                                matrix[row][col] = 0;

        if(firstRowValue == 0)
                for(int col = 0; col < cols; col++)
                        matrix[0][col] = 0;
}

//Time Complexity: O(n*m)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/set-matrix-zeroes/