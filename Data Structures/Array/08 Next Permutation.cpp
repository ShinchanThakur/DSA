//NEXT PERMUTATION (NEXT LEXICOGRAPHICALLY GREATER PERMUTATION)

void nextPermutation(vector<int>& arr) {
	int arr_size =  arr.size();
	int numberBeforePeakFromRight = -1;
	for(int i=arr_size-2; i>=0; i--)
		if(arr[i] < arr[i+1]){
			numberBeforePeakFromRight = i;
			break;
		}      
	if(numberBeforePeakFromRight<0)
		reverse(arr.begin(), arr.end());
	else{
		int smallestNumberGreaterThanPeaksLeft;
		for(int i=arr_size-1; i>numberBeforePeakFromRight; i--)
			if(arr[i] > arr[numberBeforePeakFromRight]){
				smallestNumberGreaterThanPeaksLeft = i;
				break;
			}
		swap(arr[numberBeforePeakFromRight], arr[smallestNumberGreaterThanPeaksLeft]);
		reverse(arr.begin() + numberBeforePeakFromRight + 1, arr.end());
	}
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/next-permutation/