//NEXT GREATER ELEMENT

//FOR SIMPLE ARRAY

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> s;
    for(int i=n-1; i>=0; i--){
        while(s.size() and s.top() <= arr[i])
            s.pop();
        if(s.size())
            nge[i] = s.top();
        s.push(arr[i]);
    }
    return nge;
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/next-greater-element-i/

/********************************************************************************************************/

//FOR CIRCULAR ARRAY

vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> s;
    for(int i= 2*n - 1; i>=0; i--){
        while(s.size() and s.top() <= arr[i%n])
            s.pop();
        if(i < n and s.size())
            nge[i] = s.top();
        s.push(arr[i%n]);
    }
    return nge;
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/next-greater-element-ii/