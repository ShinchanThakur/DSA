//FOUR SUM PROBLEM

//Brute force -> n^4
//Three pointers and binary search -> (n^3)logn
//Two pointers and simple two sum -> n^3
vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> v;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n-3;i++)
        {
            if(i!=0 and arr[i]==arr[i-1])
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j!=i+1 and arr[j]==arr[j-1])
                    continue;
                int start = j+1, end = n-1;
                while(start<end)
                {
                    long long int sum = arr[i];
                    sum += arr[j];
                    sum += arr[start];
                    sum += arr[end];
                    if(sum<target)
                        start++;
                    else if(sum>target)
                        end--;
                    else{
                        vector<int> ans;
                        ans.push_back(arr[i]);
                        ans.push_back(arr[j]);
                        ans.push_back(arr[start]);
                        ans.push_back(arr[end]);
                        v.push_back(ans);
                        
                        while(start<end and arr[start]==arr[start+1])
                            start++;
                        while(start<end and arr[end]==arr[end-1])
                            end--;
                        start++;
                        end--;
                    }
                }
            }
        }
        return v;
    }

//This solution works and hashing fails causing TLE
//Look into this matter

/*************************************************************************************/
    
//HASHING
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	unordered_map<int, vector<pair<int, int>>> sumOfTwoElementsVsIndexMap;
	set<vector<int>> resultSet;
	for(int i=0; i<nums.size(); i++){
		for(int j=i+1; j<nums.size(); j++){
			int currentTwoElementsSum = nums[i] + nums[j];
			if(sumOfTwoElementsVsIndexMap.find(target - currentTwoElementsSum) != sumOfTwoElementsVsIndexMap.end()){
				vector<pair<int, int>> listOfCandidates = sumOfTwoElementsVsIndexMap.find(target - currentTwoElementsSum) -> second;
				for(pair<int, int> candidate: listOfCandidates){
					int k = candidate.first, l = candidate.second;
					if(k!=i and k!=j and l!=i and l!=j){
						vector<int> quad = {i, j, k, l};
						sort(quad.begin(), quad.end());
						resultSet.insert(quad);
					}
				}
			}
			sumOfTwoElementsVsIndexMap[currentTwoElementsSum].push_back({i, j});
		}
	}
	vector<vector<int>> resultVector;
	for(vector<int> quad: resultSet)
		resultVector.push_back(quad);
	return resultVector;
}

//Time Complexity: O(n^2)
//Space Complexity: O(n^2)

//Problem Link: https://leetcode.com/problems/4sum/

// Read this link for better approaches
// https://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/