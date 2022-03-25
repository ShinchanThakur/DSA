//CELEBRITY PROBLEM

// A is a celebrity if A knows no one and
// Everyone knows A

// BRUTE FORCE

//Calculate indegree and outdegree for all
//The one with n-1 indegree and 0 outdegree is celebrity

//Time complexity: O(n^2)
//Space complexity: O(n)        -> For indegree and outdegree array

/*********************************************************************************************************/

//Stack
//Space complexity: O(n)
int findPossibleCelebrity(vector<vector<int> >& knows, int n){
    stack<int> s;
    for(int i=0; i<n; i++)      s.push(i);
    int a, b;
    while(s.size() > 1){
        a = s.top();    s.pop();
        b = s.top();    s.pop();
        if(knows[a][b])     s.push(b);
        else                s.push(a);
    }
    return s.top();
}

//Recursion
//Space complexity: O(n)    ->Recursion stack
int findPossibleCelebrity(vector<vector<int> >& knows, int n){
    if(n == 0)
        return -1;

    int potentialCelebrity = findPossibleCelebrity(knows, n-1);
    if(potentialCelebrity == -1 or knows[potentialCelebrity][n-1])
        return n-1;
    if(knows[n-1][potentialCelebrity])
        return potentialCelebrity;
    return -1;
}

//Two pointers
//Space complexity: O(1)
int findPossibleCelebrity(vector<vector<int> >& knows, int n){
    int a = 0, b = n-1;
    while(a < b){
        if(knows[a][b])
            a++;
        else
            b--;
    }
    return a;
}

int celebrity(vector<vector<int> >& knows, int n) 
{
    int potentialCelebrity = findPossibleCelebrity(knows, n);
    if(potentialCelebrity == -1)
        return -1;
    int peopleKnowingPotentialCelebrity = 0;
    for(int i=0; i<n; i++){
        if(i == potentialCelebrity)     continue;
        if(knows[potentialCelebrity][i])    return -1;
        if(knows[i][potentialCelebrity])    peopleKnowingPotentialCelebrity++;
    }
    if(peopleKnowingPotentialCelebrity == n-1)
        return potentialCelebrity;
    return -1;
}

//Time complexity: O(n)

//Problem link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1