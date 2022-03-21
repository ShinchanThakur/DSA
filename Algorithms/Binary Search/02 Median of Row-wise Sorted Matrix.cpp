//MEDIAN IN A ROW-WISE SORTED MATRIX

int median(vector<vector<int>> &matrix, int rows, int cols){
    int mini = matrix[0][0], maxi = matrix[0][0];
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            mini = min(mini, matrix[i][j]),     maxi = max(maxi, matrix[i][j]);
    int left = mini, right = maxi, mid;
    int numbersSmallerEqualToMedian = (rows * cols + 1) / 2;
    int numbersSmallerEqualToMid;
    while(left < right){
        mid = left + (right - left)/2;
        numbersSmallerEqualToMid = 0;
        for(int i=0; i<rows; i++)
            numbersSmallerEqualToMid += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        if(numbersSmallerEqualToMid < numbersSmallerEqualToMedian)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

//Time complexity: O(r * log(c) * 32)       r -> number of rows
//                                          log(c) -> for upper bound in each row with c columns
//                                          32 -> log2(2^32) = 32 -> For 32 bits, each number can take maximum of 2^32 values
//                                                And our search space is therefore at max 2^32
//Space complexity: O(1)

//Problem Link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1/