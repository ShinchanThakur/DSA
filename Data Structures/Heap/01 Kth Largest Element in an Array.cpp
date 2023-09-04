// Kth LARGEST ELEMENT IN AN ARRAY

class Solution
{
    int nlognSolution(vector<int> &nums, int k)
    {
        int kthLargest;
        priority_queue<int> maxHeap;
        for (int num : nums)
            maxHeap.push(num);
        while (--k)
            maxHeap.pop();
        kthLargest = maxHeap.top();
        return kthLargest;
    }
    int nlogkSolution(vector<int> &nums, int k)
    {
        int kthLargest;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
        kthLargest = minHeap.top();
        return kthLargest;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return nlogkSolution(nums, k);
    }
};

// Time Complexity: O(nlogk)
// Space Complexity: O(logk)

// Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/