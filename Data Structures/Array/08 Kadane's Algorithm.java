class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int maxEndingHere = 0, maxi = nums[0];
        int start = 0, end = 0;
        for(int i=0; i<n; i++){
            maxEndingHere += nums[i];
            if(maxEndingHere > maxi){
                maxi = maxEndingHere;
                end = i;
                start = currStart;
            }
            if(maxEndingHere < 0){
                maxEndingHere = 0;
                currStart = i+1;
            }
        }
        return maxi;
    }
}
