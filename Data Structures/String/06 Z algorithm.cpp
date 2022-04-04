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

void getZindex(string s, int z[], int sLength){
    int startOfCurrMatch = 0, endOfCurrMatch = 0, currMatchingInd, matchingLength, remainingMatchingInterval;
    for(int i=1; i<sLength; i++){
        if(i > endOfCurrMatch){
            startOfCurrMatch = endOfCurrMatch = i;
            while(endOfCurrMatch < sLength and s[endOfCurrMatch - startOfCurrMatch] == s[endOfCurrMatch])
                endOfCurrMatch++;
            endOfCurrMatch--;
            matchingLength = endOfCurrMatch - startOfCurrMatch + 1;
            z[i] = matchingLength;
        }
        else{
            currMatchingInd = i - startOfCurrMatch;
            remainingMatchingInterval = endOfCurrMatch - i + 1;
            if(z[currMatchingInd] < remainingMatchingInterval)
                z[i] = z[currMatchingInd];
            else{
                startOfCurrMatch = i;
                while(endOfCurrMatch < sLength and s[endOfCurrMatch - startOfCurrMatch] == s[endOfCurrMatch])
                    endOfCurrMatch++;
                endOfCurrMatch--;
                matchingLength = endOfCurrMatch - startOfCurrMatch + 1;
                z[i] = matchingLength;
            }
        }
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