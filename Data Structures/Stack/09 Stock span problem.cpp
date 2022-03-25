//STOCK SPAN PROBLEM

//USING STACK

vector <int> calculateSpan(int price[], int n)
{
    vector<int> span(n);
    stack<int> s;
    for(int i=0; i<n; i++){
        while(s.size() and price[s.top()] <= price[i])
            s.pop();
        if(s.size())    span[i] = i - s.top();
        else            span[i] = i + 1;
        s.push(i);
    }
    return span;
}

//Time complexity: O(n)
//Space complexity: O(n)

//USING DP

vector <int> calculateSpan(int price[], int n)
{
    vector<int> span(n, 1);
    for(int i=1; i<n; i++){
        int currentSpan = 1;
        while(i - currentSpan >= 0 and price[i - currentSpan] <= price[i])
            currentSpan += span[i - currentSpan];
        span[i] = currentSpan;
    }
    return span;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/online-stock-span/
//              https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/