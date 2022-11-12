class Solution {
    public static void swap(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public void sortColors(int[] nums) {
        int n = nums.length;
        int curr=0, lastZero = 0, firstTwo = n-1;
        while(curr <= firstTwo){
            switch(nums[curr]){
                case 0: swap(nums, lastZero++, curr++);
                        break;
                case 1: curr++;
                        break;
                case 2: swap(nums, curr, firstTwo--);
            }
        }
    }
}
