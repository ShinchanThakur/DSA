//SET MATRIX ZERO

void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row0 = 1;

        for(int i=0,j=0;j<columns;j++)
            if(matrix[i][j]==0)
                row0 = 0;
        for(int i=1;i<rows;i++)
            for(int j=0;j<columns;j++)
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for(int i=1;i<rows;i++)
            for(int j=columns-1;j>=0;j--)
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j] = 0;
        if(row0==0)
            for(int i=0,j=0;j<columns;j++)
                matrix[i][j] = 0;
    }

//Time Complexity: O(n*m)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/set-matrix-zeroes/