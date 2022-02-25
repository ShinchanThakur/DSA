//PASCAL'S TRIANGLE

vector<vector<int>> generatePascalTriangle(int numRows) {
    vector<vector<int>> pascalTriangle(numRows);
    for(int row = 0; row < numRows; row++){
        pascalTriangle[row].resize(row+1);
        pascalTriangle[row][0] = pascalTriangle[row][row] = 1;
        for(int col = 1; col < row; col++)
            pascalTriangle[row][col] = pascalTriangle[row-1][col-1] + pascalTriangle[row-1][col];
    }
    return pascalTriangle;
}

//Time Complexity: O(n^2)
//Space Complexity: O(n^2)

//Problem Link: https://leetcode.com/problems/pascals-triangle/