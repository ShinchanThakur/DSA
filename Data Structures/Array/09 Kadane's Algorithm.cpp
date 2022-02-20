//KADANE'S ALGORITHM

int maxSubArray(vector<int>& arr) {
        int maxSumFinal = arr[0], maxEndingHere = 0;
        int startingIndexOfMaxSubarray = 0, endingIndexOfMaxSubarray = 0;
        int arr_size = arr.size();
        for(int i=0; i<arr_size; i++){
                maxEndingHere += arr[i];
                if(maxEndingHere > maxSumFinal){
                        endingIndexOfMaxSubarray = i;
                        maxSumFinal = maxEndingHere;
                }
                if(maxEndingHere < 0){
                        startingIndexOfMaxSubarray = i+1;
                        maxEndingHere = 0;
                }
        }
        return maxSumFinal;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/maximum-subarray/