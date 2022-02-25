//MAX AND MIN IN ARRAY

pair<int,int> findMinMax(int arr[], int size){
	int minimum = arr[0];
	int maximum = arr[0];
	for(int i=1;i<size;i++){
		minimum = min(arr[i], minimum);
		maximum = max(arr[i], maximum);
	}
	return {minimum, maximum};
}

// TIME COMPLEXITY - O(n)
// SPACE COMPLEXITY - O(1)

//Problem Link - https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/