//FOUR SUM PROBLEM

//Brute force -> n^4
//Three pointers and binary search -> (n^3)logn
//Two pointers and simple two sum -> n^3
vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>> allQuads;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i=0; i<n-3; i++){
        if(i != 0 and arr[i] == arr[i-1])
            continue;
        for(int j = i+1; j < n-2; j++){
            if(j != i+1 and arr[j] == arr[j-1])
                continue;
            int left = j+1, right = n-1;
            while(left < right){
                long long int sum = arr[i]; sum += arr[j]; sum += arr[left]; sum += arr[right];
                if(sum < target)
                    left++;
                else if(sum > target)
                    right--;
                else{
                    allQuads.push_back({arr[i], arr[j], arr[left], arr[right]});
                    while(left < right and arr[left] == arr[left+1])
                        left++;
                    while(left < right and arr[right] == arr[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
    }
    return allQuads;
}

//This solution works and hashing fails causing TLE
//Look into this matter
//See this for hashing based solution - https://www.techiedelight.com/4-sum-problem/#:~:text=4%2Dsum%20problem%3A%20Given%20an,quadruplets)%20having%20a%20given%20sum.&text=Output%3A%20Quadruplet%20exists.

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