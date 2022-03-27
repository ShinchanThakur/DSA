//RABIN KARP
//String matching algo

vector<int> stringMatch(string &str, string &pat) {
    long long d = 256, p = 998244353, patLen = pat.length(), strLen = str.length(), h = 1, patHash = 0, strHash = 0;
    //d -> no. of different possible characters (generally)
    //p -> prime number to take mod of hash
    //h -> pow(d, patLen -1)
    //changing the value of d and p may affect answer if we do not check every character after matching hash
    for(int i=0; i < patLen-1; i++)
        h = (h * d) % p;
    for(int i=0; i< patLen; i++){
        patHash = (patHash * d + pat[i]) % p;
        strHash = (strHash * d + str[i]) % p;
    }
    int j;
    vector<int> matchPositions;
    for(int i=0; i <= strLen - patLen; i++){
        if(patHash == strHash){
            for(j=0; j < patLen; j++)
                if(str[i+j] != pat[j])  break;
            if(j == patLen)
                matchPositions.push_back(i);
        }
        if(i < strLen - patLen){
            strHash = (d * (strHash - h * str[i]) + str[i + patLen]) % p;
            if(strHash < 0)
                strHash += p;
        }
    }
    return matchPositions;
}

//Time complexity: Theta(m+n)   ->Average and best case
//                 O(m*n)       ->Worst case
//Space complexity: O(1)

//Problem link: https://bit.ly/3FvnLaN