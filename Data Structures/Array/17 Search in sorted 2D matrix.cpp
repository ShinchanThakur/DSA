//SEARCH IN A SORTED 2-D MATRIX

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

bool searchSortedMatrix(vector<vector<int>>& matrix, int target) {
	int rows = matrix.size(), cols = matrix[0].size();
	int low = 0, high = rows*cols-1, mid;
	while(low <= high){
		mid = low + (high - low)/2;
		int row = mid / cols;
		int col = mid % cols;
		int midElement = matrix[row][col];
		if(midElement < target)
			low = mid + 1;
		else if(midElement > target)
			high = mid - 1;
		else
			return true;
	}
	return false;
}

//Time Complexity: O(log(n*m))
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/search-a-2d-matrix/