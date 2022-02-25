//COUNT INVERSIONS IN AN ARRAY

//INVERSION: Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// inversionCount += mid-leftIndex+1 -> ONLY IMPORTANT STATEMENT IN THE WHOLE CODE

int merge(int arr[], int temp[], int left, int mid, int right){
	int inversionCount = 0;
	int leftIndex = left, rightIndex = mid+1, tempIndex = left;
	while(leftIndex <= mid and rightIndex <= right){
		if(arr[leftIndex] <= arr[rightIndex])
			temp[tempIndex++] = arr[leftIndex++];
		else{
			inversionCount += (mid - leftIndex + 1);
			temp[tempIndex++] = arr[rightIndex++];
		}
	}
	while(leftIndex <= mid)
		temp[tempIndex++] = arr[leftIndex++];
	while(rightIndex <= right)
		temp[tempIndex++] = arr[rightIndex++];
	for(int i=left; i<=right; i++)
		arr[i] = temp[i];
	return inversionCount;
}

int mergeSort(int arr[], int temp[], int left, int right){
	if(right <= left)
		return 0;
	int mid = left + (right-left)/2;
	int inversionCount = mergeSort(arr, temp, left, mid);
	inversionCount += mergeSort(arr, temp, mid+1, right);
	inversionCount += merge(arr, temp, left, mid, right);
	return inversionCount;
}

int countInversions(int arr[], int n){
	int temp[n];
	return mergeSort(arr, temp, 0, n-1);
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

//Problem Link: https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website