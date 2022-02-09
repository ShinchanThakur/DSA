//NEXT PERMUTATION (NEXT LEXICOGRAPHICALLY GREATER PERMUTATION)

void nextPermutation(vector<int>& arr) {
	int arr_size =  arr.size();
	int peak = -1;
	for(int i=arr_size-2; i>=0; i--)
		if(arr[i] < arr[i+1]){
			peak = i;
			break;
		}      
	if(peak<0)
		reverse(arr.begin(), arr.end());
	else{
		int smallestNumberGreaterThanPeak;
		for(int i=arr_size-1; i>peak; i--)
			if(arr[i] > arr[peak]){
				smallestNumberGreaterThanPeak = i;
				break;
			}
		swap(arr[peak], arr[smallestNumberGreaterThanPeak]);
		reverse(arr.begin() + peak + 1, arr.end());
	}
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/next-permutation/