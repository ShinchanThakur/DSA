class Solution {
    public void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public void reverse(int arr[], int i, int j){
        while(i < j)    swap(arr, i++, j--);
    }
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int numLeftOfPeak = n-2, i = n-2;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        numLeftOfPeak = i;
        if(numLeftOfPeak >= 0){
            int j = n-1;
            while(nums[j] <= nums[i]) j--;
            int numJustGreaterThanPeaksLeft = j;
            swap(nums, numLeftOfPeak, numJustGreaterThanPeaksLeft);
        }
        reverse(nums, numLeftOfPeak + 1, n-1);
    }
}
