//LENGTH OF LONGEST SUBARRAY WITH SUM K

int lengthOfLongestSubarrayWithSumK(vector<int>& nums, int k) {
    map<int,int> prefixSumVsIndexMap;
    int prefixSum = 0, longestSubarrayLength = 0;
    for(int i=0; i<nums.size(); i++){
        prefixSum += nums[i];
        if(prefixSum == k)
            longestSubarrayLength = i + 1;
        if(prefixSumVsIndexMap.find( prefixSum - k) != prefixSumVsIndexMap.end())
            longestSubarrayLength = max(longestSubarrayLength, i - prefixSumVsIndexMap[ prefixSum - k]);
        if(prefixSumVsIndexMap.find( prefixSum ) == prefixSumVsIndexMap.end())
            prefixSumVsIndexMap[ prefixSum ] = i;
    }
    return longestSubarrayLength;
}

//Time Complexity - O(nlogn)
//Space Complexity - O(n)

//Problem link - https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/#
//               https://leetcode.com/problems/continuous-subarray-sum/
//               https://leetcode.com/problems/subarray-sum-equals-k/