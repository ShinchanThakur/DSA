//STRING TO INT

bool myIsDigit(char ch){
    return ('0' <= ch and ch <= '9');
}

int myAtoi(string s) {
    int numInt = 0, i = 0, n = s.length(), sign = 1, digit;
    while(i<n and s[i] == ' ')      i++;
    if(i<n and s[i] == '-')         sign = -1, i++;
    else if(i<n and s[i] == '+')    i++;
    while(i<n and myIsDigit(s[i])){
        digit = s[i++] - '0';
        if(numInt > INT_MAX / 10 or (numInt == INT_MAX / 10 and digit > INT_MAX % 10))
            return (sign == 1) ? INT_MAX : INT_MIN;
        numInt = numInt*10 + digit;
    }
    return numInt * sign;
}

//Time complexity: O(log(n))
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/string-to-integer-atoi/

/**********************************************************************************************************/

//INT TO STRING

string myToString(int a){
    long long int x = a;
    string num = "";
    if(x == 0)
        return "0";
    if(x < 0){
        num += '-';
        x *= -1;
    }
    char digit;
    while(x){
        digit = x%10 - '0';
        num += digit;
        x /= 10;
    }
    return num;
}

//Time complexity: O(log(n))
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/palindrome-number/