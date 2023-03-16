Find if a number is palindrome

bool isPalindrome(int x) {
    string s = to_string(x);
    for(int i=0; i<s.size()/2; i++)
        if(s[i] != s[s.size()-1-i])
            return false;
    return true;
}
Time Complexity: O(n)
Space Complexity: O(n)

  
bool isPalindrome(int x) {
    if(x < 0 || (x%10 == 0 && x!=0))
        return false;
    int halfReverseNum = 0;
    while(x > halfReverseNum){
        halfReverseNum = halfReverseNum * 10 + x % 10;
        x/=10;
    }
    return x == halfReverseNum || x == halfReverseNum / 10;
}
Time Complexity: O(n)
Space Complexity: O(1)
  
https://leetcode.com/problems/palindrome-number/description/
