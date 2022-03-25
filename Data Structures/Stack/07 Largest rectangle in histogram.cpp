//LARGEST RECTANLGE IN HISTOGRAM

//BRUTE FORCE

int largestRectangleArea(vector<int>& heights) {
    int minHeight, area, largestArea = 0, n = heights.size();
    for(int left = 0; left < n; left++){
        minHeight = heights[left];
        for(int right = left; right < n; right++){
            minHeight = min(minHeight, heights[right]);
            area = minHeight * (right - left + 1);
            largestArea = max(largestArea, area);
        }
    }
    return largestArea;
}

//Time complexity: O(n*n)
//Space complexity: O(1)

/**************************************************************************************************/

//BETTER APPROACH

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> leftSmaller(n, -1), rightSmaller(n, n);
    stack<int> s;
    for(int i=0; i<n; i++){
        while(s.size() and heights[s.top()] >= heights[i])
            s.pop();
        if(s.size())
            leftSmaller[i] = s.top();
        s.push(i);
    }
    while(s.size())
        s.pop();
    for(int i = n-1; i>=0; i--){
        while(s.size() and heights[s.top()] >= heights[i])
            s.pop();
        if(s.size())
            rightSmaller[i] = s.top();
        s.push(i);
    }
    int area, largestArea = 0;
    for(int i=0; i<n; i++){
        area = heights[i] * (rightSmaller[i] - leftSmaller[i] - 1);
        largestArea = max(area, largestArea);
    }
    return largestArea;
}

//Time complexity: O(2*n)
//Space complexity: O(3*n)

/**************************************************************************************************/

//BEST APPROACH

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), largestArea = 0, area, right, left, height;
    stack<int> s;
    for(int i=0; i<=n; i++){
        while(s.size() and (i ==n or heights[s.top()] >= heights[i])){
            height = heights[s.top()];
            s.pop();
            right = i;
            left = s.size() ? s.top() : -1;
            area = height * (right - left - 1);
            largestArea = max(area, largestArea);
        }
        s.push(i);
    }
    return largestArea;
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/