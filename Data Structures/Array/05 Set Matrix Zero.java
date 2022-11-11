class Solution {
    public void setZeroes(int[][] matrix) {
        Boolean firstRowZero = false;
        int numRows = matrix.length, numCols = matrix[0].length;
        for(int i=0, j=0; j<numCols; j++)
            if(matrix[i][j] == 0){
                firstRowZero = true;
                break;
            }
        for(int i=1; i<numRows; i++)
            for(int j=0; j<numCols; j++)
                if(matrix[i][j] == 0)   matrix[i][0] = matrix[0][j] = 0;
        for(int i=1; i<numRows; i++)
            for(int j=numCols-1; j>=0; j--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
        if(firstRowZero)
            for(int i=0, j=0; j<numCols; j++)
                matrix[i][j] = 0;
    }
}
