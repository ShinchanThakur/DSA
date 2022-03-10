//FIND MAXIMUM NUMBER OF CONSECUTIVE ONES IN A BINARY ARRAY

int findMaxConsecutiveOnes(vector<int>& arr) {
    int countOnes = 0, maxOnes = 0;
    for(int num: arr){
        if(num)
            countOnes++;
        else
            countOnes = 0;
        maxOnes = max(maxOnes, countOnes);
    }
    return maxOnes;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem Link: https://leetcode.com/problems/max-consecutive-ones/