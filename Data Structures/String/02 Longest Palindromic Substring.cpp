//LONGEST PALINDROMIC SUBSTRING

//DP

string longestPalindrome(string s) {
    int n = s.length(), start = 0, maxLength = 1;
    bool table[n][n];
    memset(table, 0, sizeof(table));
    for(int i=0; i<n; i++)
        table[i][i] = true;
    for(int i=0; i<n-1; i++)
        if(s[i] == s[i+1]){
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    for(int k=3; k<=n; k++)
        for(int i=0; i<n-k+1; i++){
            int j = i + k - 1;
            if(table[i+1][j-1] and s[i] == s[j]){
                table[i][j] = true;
                if(k > maxLength){
                    maxLength = k;
                    start = i;
                }
            }
        }
    return s.substr(start, maxLength);
}

//Time complexity: O(n^2)
//Space complexity: O(n^2)

/********************************************************************************************************/

//OPTIMAL

string longestPalindrome(string s) {
    int n = s.length(), start = 0, maxLength = 1, low, high, len;
    for(int i=0; i<n; i++){
        low = i-1, high = i+1;
        while(high < n and s[i] == s[high])     high++;
        while(low >= 0 and s[i] == s[low])      low--;
        while(low >= 0 and high < n and s[low] == s[high])      low--, high++;
        len = high - low - 1;
        if(len > maxLength){
            maxLength = len;
            start = low + 1;
        }
    }
    return s.substr(start, maxLength);
}

//Time complexity: O(n^2)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/longest-palindromic-substring/