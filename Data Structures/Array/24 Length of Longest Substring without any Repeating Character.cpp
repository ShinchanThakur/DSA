// LENGTH OF LONGEST SUBSTRING WITHOUT REPEATING CHARACTER

int lengthOfLongestSubstring(string str) {
	int lengthOfLongestSubstring(string str) {
	int stringStartIndex = 0, stringEndIndex = 0, lengthOfLongestSubstringWithoutRepeatingChar = 0, currentStringLength;
	map<char, int> charVsItslastFoundIndexMap;
	//using 1 based indexing since map initially stores 0 for unused keys
    if(str.length() >= 1)
        lengthOfLongestSubstringWithoutRepeatingChar = 1;
	for(int i=0; i < str.length(); i++){
		stringStartIndex = max(stringStartIndex, charVsItslastFoundIndexMap[str[i]] + 1);
		stringEndIndex = i+1;
		currentStringLength = stringEndIndex - stringStartIndex + 1;
		lengthOfLongestSubstringWithoutRepeatingChar = max(lengthOfLongestSubstringWithoutRepeatingChar, currentStringLength);
		charVsItslastFoundIndexMap[str[i]] = i+1;
	}
	return lengthOfLongestSubstringWithoutRepeatingChar;
}

//Time Complexity - O(n)
//Space Complexity - O(1)

//Problem Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/