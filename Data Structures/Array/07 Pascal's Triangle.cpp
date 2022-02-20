//PASCAL'S TRIANGLE

vector<vector<int>> generatePascalTriangle(int numRows) {
        vector<vector<int>> pascalTriangle(numRows);
        for(int i=0;i<numRows;i++){
                pascalTriangle[i].resize(i+1);
                pascalTriangle[i][0] = pascalTriangle[i][i] = 1;
                for(int j=1;j<i;j++)
                        pascalTriangle[i][j] = pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j];
        }
        return pascalTriangle;
}

//Time Complexity: O(n^2)
//Space Complexity: O(n^2)

//Problem Link: https://leetcode.com/problems/pascals-triangle/