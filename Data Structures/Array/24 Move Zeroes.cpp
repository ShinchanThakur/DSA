//MOVE ZEROES

void moveZeroes(vector<int> &arr) {
	int lastNonZeroIndex = 0;
	for(int i=0; i<arr.size(); i++)
		if(arr[i] != 0)
			swap(arr[lastNonZeroIndex++], arr[i]);
}

//Time Complexity - O(n)
//Space Complexity - O(1)

//Problem Link - https://leetcode.com/problems/move-zeroes/