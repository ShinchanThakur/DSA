//COUNT SUBARRAYS WITH GIVEN XOR

int countSubArraysWithGivenXor(vector<int> &nums, int target) {
    int prefixXor = 0;
    map<int, int> prefixXorVsCount;
    int subArrayCountWithGivenXor = 0;
    for(int num: nums){
        prefixXor ^= num;
        if(prefixXor == target)
            subArrayCountWithGivenXor++;
        int xorCompliment = prefixXor ^ target;
        subArrayCountWithGivenXor += prefixXorVsCount[ xorCompliment ];
        prefixXorVsCount[ prefixXor ]++;
    }
    return subArrayCountWithGivenXor;
}

//Time Complexity: O(nlogn)
//Space Complexity: O(n)

//Problem Link: https://www.interviewbit.com/problems/subarray-with-given-xor/