//PRINT ALL SUBSEQUENCES

//USING BIT MANIPULATION

vector<string> AllPossibleStrings(string s){
    int n = s.length();
    vector<string> allSubs;
    for(int num = 0; num < (1 << n); num++){
        string sub = "";
        for(int i=0; i<n; i++){
            if(num & (1 << i))
                sub += s[i];
        }
        if(sub != "")
            allSubs.push_back(sub);
    }
    sort(allSubs.begin(), allSubs.end());
    return allSubs;
}

/**********************************************************************************************************/

//USING RECURSION (Backtracking)

void getAllSubs(string s, int ind, string sub, vector<string> &allSubs){
    if(ind == s.length()){
        if(sub != "")
            allSubs.push_back(sub);
        return;
    }
    getAllSubs(s, ind + 1, sub + s[ind], allSubs);
    getAllSubs(s, ind + 1, sub, allSubs);
}

vector<string> AllPossibleStrings(string s){
    int ind = 0;
    string sub = "";
    vector<string> allSubs;
    getAllSubs(s, ind, sub, allSubs);
    sort(allSubs.begin(), allSubs.end());
    return allSubs;
}

//Time complexity: O(2^n log(2^n))      2^n -> number of subsequences , Sorting them all
//Space complexity: O(2^n * n)

//Problem link: https://practice.geeksforgeeks.org/problems/power-set4302/1#