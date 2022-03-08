//FIND LENGTH OF LONGEST CONSECUTIVE SEQUENCE IN AN ARRAY

//Brute force approach -> Sorting (O(nlogn))

//Optimal -> HASHING

int longestConsecutiveSequence(vector<int>& nums) {
    unordered_set<int> hashSet;
    int longestConsecutiveStreak = 0;
    for(int num:nums)
        hashSet.insert(num);
    for(int num: nums)
        if(!hashSet.count(num-1)){
            int currentStreakLength = 1;
            int currentNum = num;
            while(hashSet.count(currentNum+1))
                currentStreakLength++, currentNum++;
            longestConsecutiveStreak = max(longestConsecutiveStreak, currentStreakLength);
        }
    return longestConsecutiveStreak;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/