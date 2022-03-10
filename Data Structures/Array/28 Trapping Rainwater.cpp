//TRAPPING RAINWATER

//Given an array of non-negative integers representation elevation of ground. 
//Your task is to find the water that can be trapped after raining.

int trappingRainWater(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, waterTrapped = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] > leftMax)
                leftMax = height[left];
            else
                waterTrapped += leftMax - height[left];
            left++;
        }
        else{
            if(height[right] > rightMax)
                rightMax = height[right];
            else
                waterTrapped += rightMax - height[right];
            right--;
        }
    }
    return waterTrapped;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/trapping-rain-water/