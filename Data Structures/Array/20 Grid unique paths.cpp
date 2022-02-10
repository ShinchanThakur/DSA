//GRID UNIQUE PATHS

//count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

//RECURSION

int findUniquePathsFromStartToEnd(int startRow, int startCol, int endRow, int endCol){
	if(startRow == endRow and startCol == endCol)
		return 1;
	if(startRow > endRow or startCol > endCol)
		return 0;
	int goDown = findUniquePathsFromStartToEnd(startRow + 1, startCol, endRow, endCol);
	int goRight = findUniquePathsFromStartToEnd(startRow, startCol + 1, endRow, endCol);
	return goDown + goRight;
}

int uniquePaths(int m, int n){
	int startRow = 0, startCol = 0, endRow = m-1, endCol = n-1;
	return findUniquePathsFromStartToEnd(startRow, startCol, endRow, endCol);
}

//Time and space complexity: Exponential

/*****************************************************************************************/

//DP

int findUniquePathsFromStartToEnd(int startRow, int startCol, int endRow, int endCol, vector<vector<int>> &uniquePaths){
	if(startRow == endRow and startCol == endCol)
		return 1;
	if(startRow > endRow or startCol > endCol)
		return 0;
	if(uniquePaths[startRow][startCol] != -1)
		return uniquePaths[startRow][startCol];
	int goDown = findUniquePathsFromStartToEnd(startRow + 1, startCol, endRow, endCol, uniquePaths);
	int goRight = findUniquePathsFromStartToEnd(startRow, startCol + 1, endRow, endCol, uniquePaths);
	return uniquePaths[startRow][startCol] = goDown + goRight;
}

int uniquePaths(int m, int n){
	int startRow = 0, startCol = 0, endRow = m-1, endCol = n-1;
	vector<vector<int>> uniquePaths(m+1, vector<int>(n+1, -1));
	return findUniquePathsFromStartToEnd(startRow, startCol, endRow, endCol, uniquePaths);
}

//Time and space complexity: O(m*n)

/*****************************************************************************************/

//COMBINATORICS

int nCr(int n, int r){
	r = min(r, n-r);
	double ncr = 1;
	for(int i=1; i<=r; i++)
		ncr = ncr * (n-r+i) / i;
	return ncr;
}

int uniquePaths(int m, int n){
	return nCr(m+n-2, m-1);
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/unique-paths/