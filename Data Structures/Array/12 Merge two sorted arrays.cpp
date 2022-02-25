//MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE

//USING INSERTION SORT ALGORITHM

void sendFirstElementToRightPlaceUsingInsertionSort(vector<int>& arr, int arr_size){
	int firstElement = arr[0], i;
	for(i=1; i<arr_size and arr[i]<firstElement; i++)
		arr[i-1] = arr[i];
	arr[i-1] = firstElement;
}

void mergeTwoSortedArrays(vector<int>& arr, int arr_size, vector<int>& brr, int brr_size){
	for(int i=0; i<arr_size; i++){
		if(arr[i] > brr[0])
			swap(arr[i], brr[0]);
		sendFirstElementToRightPlaceUsingInsertionSort(brr, brr_size);
	}
}

//Time Complexity: O(n^2)
//Space Complexity: O(1)

/*******************************************************************************************/

//GAP METHOD

int findGap(int oldGap){
	int gap;
	if(oldGap <= 1)
		gap = 0;
	else
		gap = ceil((float)oldGap/ 2);
	return gap;
}

void mergeTwoSortedArrays(vector<int>& arr, int arr_size, vector<int>& brr, int brr_size){
	int gap = findGap(arr_size + brr_size);
	while(gap){
		int i=0, j=gap;
		while(j < (arr_size + brr_size)){
			if(j < arr_size){
				if(arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
			else{
				if(i < arr_size){
					if(arr[i] > brr[ j - arr_size ])
						swap(arr[i], brr[ j - arr_size ]);
				}
				else{
					if(brr[ i - arr_size ] > brr[ j - arr_size ])
						swap(brr[ i - arr_size ], brr[ j - arr_size ]);
				}
			}
			i++;
			j++;
		}
		gap = findGap(gap);
	}
}

//Time Complexity: O(n*log(n))		-> (m+n)*log(m+n)
//Space Complexity: O(1)

/*******************************************************************************************/

//Problem Link: https://leetcode.com/problems/merge-sorted-array/

//Read this post for solutions in O(n)