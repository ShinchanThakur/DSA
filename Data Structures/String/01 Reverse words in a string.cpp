//REVERSE WORDS IN A STRING

string reverseWords(string s) {
    int wordStart = 0, wordEnd = 0, charCount = 0, n = s.length();
    reverse(s.begin(), s.end());
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == ' '){
            if(charCount){
                reverse(s.begin() + wordStart, s.begin() + wordEnd);
                if(wordEnd < n)      s[wordEnd++] = ' ';
                wordStart = wordEnd;
                charCount = 0;
            }
        }
        else{
            s[wordEnd++] = ch;
            charCount++;
        }
    }
    if(charCount){
        reverse(s.begin() + wordStart, s.begin() + wordEnd);
        wordEnd++;
    }
    s.erase(s.begin() + wordEnd - 1, s.end());

    return s;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/reverse-words-in-a-string/