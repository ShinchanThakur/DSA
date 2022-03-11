//PRINT ALL PALINDROMIC PARTITIONS OF A STRING
//Palindromic partition-> Dividing a string into parts such that every part is a palindrome

bool isPalindrome(string s, int start, int end){
    while(start < end)
        if(s[start++] != s[end--])
            return false;
    return true;
}

void checkAllPossiblePartitions(string s, vector<vector<string>> &reqdPartitions, vector<string> partition, int ind){
    if(ind == s.size()){
        reqdPartitions.push_back(partition);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        if(isPalindrome(s, ind, i)){
            partition.push_back(s.substr(ind, i - ind + 1));
            checkAllPossiblePartitions(s, reqdPartitions, partition, i+1);
            partition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> reqdPartitions;
    vector<string> partition;
    int ind = 0;
    checkAllPossiblePartitions(s, reqdPartitions, partition, ind);
    return reqdPartitions;
}

//Time complexity: O(2^(n-1) k*(n/2))   k->average size of a part of string
                                        // ->n/2 for checking palindrome
                                        // ->there are n-1 spaces in the string where we can put a partition
                                        // therefore we can choose to put a partition there or choose not to put a partition there
                                        // therefore 2^(n-1)
//Space complexity: O(n*x)              x-> number of palindromic partitions

//Problem link: https://leetcode.com/problems/palindrome-partitioning/


//To improve efficiency even further by removing the need to use n/2 time for checking palindrome
//Check the second approach of this link: https://leetcode.com/problems/palindrome-partitioning/solution/