//SLIDING WINDOW MAXIMUM

//Return maximum element for every window of size k

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> windowMax;
    for(int i=0; i < arr.size(); i++){
        if(dq.size() and dq.front() == i-k)
            dq.pop_front();
        while(dq.size() and arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        if(i >= k-1)
            windowMax.push_back(arr[dq.front()]);
    }
    return windowMax;
}

//Time complexity: O(n)
//Space complexity: O(k)

//Problem link: https://leetcode.com/problems/sliding-window-maximum/