// LENGTH OF LONGEST SUBSTRING WITHOUT REPEATING CHARACTER

int lengthOfLongestSubstringWithoutRepeatingCharacter(string str) {
    map<int,int> lastIndexOfChar;
    int start = 1, ans = 0;
    for(int i=0; i<str.length(); i++){
        start = max(start, lastIndexOfChar[str[i]] + 1);
        end = i+1;
        ans = max(ans, end - start + 1);
        lastIndexOfChar[str[i]] = i+1;
        //using 1 based indexing since map initially stores 0 for unused keys
    }
    return ans;
}

//Time Complexity - O(n)
//Space Complexity - O(1)

//Problem Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/