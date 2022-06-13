// Z ALGORITHM (Pattern searching)

// An element Z[i] of Z array stores length of the longest substring starting from str[i] 
// which is also a prefix of str[0..n-1]. The first entry of Z array is meaning less as 
// complete string is always prefix of itself. 

// Examples:
// str  = "aaaaaa"
// Z[]  = {x, 5, 4, 3, 2, 1}

// str = "aabaacd"
// Z[] = {x, 1, 0, 2, 1, 0, 0}

// str = "abababab"
// Z[] = {x, 0, 6, 0, 4, 0, 2, 0}

void getZindex(string s, int z[], int n){
    //l to r -> already matched
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)         //l < i < r
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int strStr(string text, string pattern) {
    string s = pattern + "$" + text;
    int sLength = s.length(), patLen = pattern.length(), ans = -1;
    int z[sLength];
    getZindex(s, z, sLength);
    for(int i = patLen + 1; i < sLength; i++){
        if(z[i] == patLen){
            ans = i-patLen-1;
            break;
        }
    }
    return ans;
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/implement-strstr/
//              https://bit.ly/3qs24UM