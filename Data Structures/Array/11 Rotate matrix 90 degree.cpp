//ROTATE MATRIX 90 DEGREE (CLOCKWISE)

//EXTRA SPACE

vector<vector<int>> rotateMatrixBy90degree(vector<vector<int>>& matrix){
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<int>> rotatedMatrix(n, vector<int>(n));
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			rotatedMatrix[j][n-i-1] = matrix[i][j];
	return rotatedMatrix;
}

//Time Complexity: O(n^2)
//Space Complexity: O(n^2)

/********************************************************************************************/

//WITHOUT EXTRA SPACE

void transpose(vector<vector<int>>& matrix, int rows, int cols){
	for(int i=0; i<rows; i++)
		for(int j=0; j<i; j++)
			swap(matrix[i][j], matrix[j][i]);
}

void reverseEveryRow(vector<vector<int>>& matrix, int rows){
	for(int i=0; i<rows; i++)
		reverse(matrix[i].begin(), matrix[i].end());
}

void rotateMatrixBy90degree(vector<vector<int>>& matrix){
	int rows = matrix.size();
	int cols = matrix[0].size();
	transpose(matrix, rows, cols);
	reverseEveryRow(matrix, rows);
}

//Time Complexity: O(n^2)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/rotate-image/