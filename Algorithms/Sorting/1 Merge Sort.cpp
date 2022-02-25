//MERGE SORT

void fillTemperoryArrays(int leftArray[], int leftArraySize, int rightArray[], int rightArraySize, int arr[], int start){
	for(int i=0; i<leftArraySize; i++)
		leftArray[i] = arr[start++];
	for(int i=0; i<rightArraySize; i++)
		rightArray[i] = arr[start++];
}

void mergeSortedArrays(int leftArray[], int leftArraySize, int rightArray[], int rightArraySize, int arr[], int start){
	int leftArrayIndex = 0, rightArrayIndex = 0;
	while(leftArrayIndex < leftArraySize and rightArrayIndex < rightArraySize){
		if(leftArray[leftArrayIndex] <= rightArray[rightArrayIndex])
			arr[start++] = leftArray[leftArrayIndex++];
		else
			arr[start++] = rightArray[rightArrayIndex++];
	}
	while(leftArrayIndex < leftArraySize)
		arr[start++] = leftArray[leftArrayIndex++];
	while(rightArrayIndex < rightArraySize)
		arr[start++] = rightArray[rightArrayIndex++];
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