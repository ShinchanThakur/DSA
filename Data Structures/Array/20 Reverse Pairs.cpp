//COUNT REVERSE PAIRS

// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j]

int countReversePairsWhileMerging(vector<int> &arr, int left, int mid, int right){
	int leftIndex = left, rightIndex = mid + 1;
	int reversePairsCount = 0;
	while(leftIndex <= mid){
		while(rightIndex <= right and arr[leftIndex] > 2ll * arr[rightIndex])
			rightIndex++;
		reversePairsCount += (rightIndex - (mid + 1));
		leftIndex++;
	}
	return reversePairsCount;
}

int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right){

	int reversePairsCount = countReversePairsWhileMerging(arr, left, mid, right);
	
	int leftIndex = left, rightIndex = mid + 1, tempIndex = left;
	while(leftIndex <= mid and rightIndex <= right)
		if(arr[leftIndex] <= arr[rightIndex])
			temp[tempIndex++] = arr[leftIndex++];
		else
			temp[tempIndex++] = arr[rightIndex++];
	while(leftIndex <= mid)
		temp[tempIndex++] = arr[leftIndex++];
	while(rightIndex <= right)
		temp[tempIndex++] = arr[rightIndex++];

	tempIndex = left;
	while(tempIndex <= right)
		arr[tempIndex++] = temp[tempIndex];

	return reversePairsCount;
}

int mergeSort(vector<int> &arr, vector<int> &temp, int left, int right){
	if(left >= right)
		return 0;
	int mid = left + (right - left)/2;
	int reversePairsCount = mergeSort(arr, temp, left, mid);
	reversePairsCount += mergeSort(arr, temp, mid+1, right);
	reversePairsCount += merge(arr, temp, left, mid, right);
	return reversePairsCount;
}

int reversePairs(vector<int>& nums){
	int arr_size = nums.size();
	vector<int> temp(arr_size);
	int left = 0, right = arr_size - 1;
	return mergeSort(nums, temp, left, right);
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

//Problem Link: https://leetcode.com/problems/reverse-pairs/