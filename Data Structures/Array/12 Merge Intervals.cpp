//MERGE OVERLAPPING SUB-INTERVALS

void addIntervalToList(vector<vector<int>>& intervals, int start, int end){
	vector<int> interval;
   	interval.push_back(start);
   	interval.push_back(end);
   	intervals.push_back(interval);
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;
    sort(intervals.begin(), intervals.end());
   	int arr_size = intervals.size();
   	int start = intervals[0][0];
   	int end = intervals[0][1];
   	addIntervalToList(mergedIntervals, start, end);
   	for(int i=1; i<arr_size; i++){
   		int previousStart = mergedIntervals.back()[0];
   		int previousEnd = mergedIntervals.back()[1];
   		start = intervals[i][0];
   		end = intervals[i][1];

   		if(previousEnd >= start)
   			mergedIntervals.back()[1] = max(previousEnd, end);
   		else
   			addIntervalToList(mergedIntervals, start, end);
   	}
    return mergedIntervals;
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

// Problem Link: https://leetcode.com/problems/merge-intervals/