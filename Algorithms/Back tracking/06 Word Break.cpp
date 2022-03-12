//WORD BREAK
//Return all possible sentences that can be made by dividing s into words from dictionary wordDict

bool isPresent(string word, vector<string> &wordDict){
    for(string s: wordDict)
        if(s == word)   return true;
    return false;
}

void findAllPossibleSentences(string sttring, vector<string> &wordDict, string sentence, int length, vector<string> &allSentences){
    for(int i=1; i <= length; i++){
        string word = sttring.substr(0, i);
        if(isPresent(word, wordDict)){
            string newSentence = sentence + word;
            if(i == n){
                allSentences.push_back(newSentence);
                return;
            }
            string remainingString = sttring.substr(i, length-i);
            int remainingLength = length - i;
            findAllPossibleSentences(remainingString, wordDict, newSentence + " ", remainingLength, allSentences);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> allSentences;
    string sentence = "";
    string remainingString = s;
    int remainingLength = s.length();
    findAllPossibleSentences(remainingString, wordDict, sentence, remainingLength, allSentences);
    return allSentences;
}

//Time complexity: O(2^n)   ->dont know how
//Space complexity: O(n^2)      ->recursive stack

//Problem link: https://leetcode.com/problems/word-break-ii/