//MERGE OVERLAPPING SUB-INTERVALS

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;
    sort(intervals.begin(), intervals.end());
    mergedIntervals.push_back(intervals[0]);
    int prevStart, prevEnd, currStart, currEnd;
    for(int i=1; i<intervals.size(); i++){
        prevStart = mergedIntervals.back()[0];
        prevEnd = mergedIntervals.back()[1];
        currStart = intervals[i][0];
        currEnd = intervals[i][1];
        if(currStart <= prevEnd)
            mergedIntervals.back()[1] = max(prevEnd, currEnd);
        else
            mergedIntervals.push_back(intervals[i]);
    }
    return mergedIntervals;
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

// Problem Link: https://leetcode.com/problems/merge-intervals/
//               https://leetcode.com/problems/insert-interval/
//               https://leetcode.com/problems/teemo-attacking/
//               https://leetcode.com/problems/partition-labels/
//               https://leetcode.com/problems/interval-list-intersections/