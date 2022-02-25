//DUTCH NATIONAL FLAG PROBLEM

//Segregate 0s and 1s in an array

void segregate0and1(int arr[], int arr_size) {
    for(int curr=0, lastZeroIndex=0; curr<arr_size; curr++)
        if(arr[curr] == 0)
            swap(arr[lastZeroIndex++], arr[curr]);
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1/#
//              https://leetcode.com/problems/move-zeroes/


//ORDER IS MAINTAINED
//Continue from here: https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/

//*************************************************************************************************

//Segregate 0s, 1s and 2s in an array

void sort012(vector<int>& nums) {
        int lastZeroIndex = 0, firstTwoIndex = nums.size()-1, curr = 0;
        while(curr <= firstTwoIndex)
                switch(nums[curr]){
                        case 0: swap(nums[lastZeroIndex++], nums[curr++]);
                                break;
                        case 1: curr++;
                                break;
                        case 2: swap(nums[curr], nums[firstTwoIndex--]);
                                break;
                }
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/sort-colors/