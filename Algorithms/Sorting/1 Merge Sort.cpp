//MERGE SORT

void fillTemperoryArrays(int leftArray[], int leftArraySize, int rightArray[], int rightArraySize, int arr[], int start){
	int j = start;
	for(int i=0; i<leftArraySize; i++)
		leftArray[i] = arr[j++];
	for(int i=0; i<rightArraySize; i++)
		rightArray[i] = arr[j++];
}

void mergeSortedArrays(int leftArray[], int leftArraySize, int rightArray[], int rightArraySize, int arr[], int start){
	int leftArrayIndex = 0, rightArrayIndex = 0, arrayIndex = start;
	while(leftArrayIndex < leftArraySize and rightArrayIndex < rightArraySize){
		if(leftArray[leftArrayIndex] <= rightArray[rightArrayIndex])
			arr[arrayIndex++] = leftArray[leftArrayIndex++];
		else
			arr[arrayIndex++] = rightArray[rightArrayIndex++];
	}
	while(leftArrayIndex < leftArraySize)
		arr[arrayIndex++] = leftArray[leftArrayIndex++];
	while(rightArrayIndex < rightArraySize)
		arr[arrayIndex++] = rightArray[rightArrayIndex++];
}

void merge(int arr[], int start, int mid, int end)
{
    int leftArraySize = mid - start + 1, rightArraySize = end - mid;
    int leftArray[leftArraySize], rightArray[rightArraySize];

    fillTemperoryArrays(leftArray, leftArraySize, rightArray, rightArraySize, arr, start);
    mergeSortedArrays(leftArray, leftArraySize, rightArray, rightArraySize, arr, start);
}

void mergeSort(int arr[], int start, int end)
{
	if(start >= end)
		return;
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

//Stable: Yes
//Algorithmic paradigm: Divide and Conquer

// Problem Link: https://practice.geeksforgeeks.org/problems/merge-sort/1/