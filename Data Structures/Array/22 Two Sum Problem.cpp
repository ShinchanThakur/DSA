//TWO SUM PROBLEM

//TWO POINTERS
vector<int> twoSum(vector<int>& nums, int target){
	vector<int> result, temp;
	temp = nums;
	sort(temp.begin(), temp.end());
	int left = 0, right = nums.size()-1;
	int num1, num2;
	while(left < right){
		if(temp[left] + temp[right] < target)
			left++;
		else if(temp[left] + temp[right] > target)
			right--;
		else{
			num1 = temp[left];
			num2 = temp[right];
			break;
		}
	}
	for(int i=0; i<nums.size(); i++)
		if(nums[i] == num1)
			result.push_back(i);
		else if(nums[i] == num2)
			result.push_back(i);
	return result;
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

/**************************************************************************************/

//HASHING
vector<int> twoSum(vector<int>& nums, int target){
	int num1, num2;
	vector<int> result;
	unordered_map<int, int> indexMap;
	for(int i=0; i<nums.size(); i++){
		if(indexMap.find(target - nums[i]) != indexMap.end()){
			num1 = i;
			num2 = indexMap[target - nums[i]];
			result = {num1, num2};
			break;
		}
		indexMap[nums[i]] = i;
	}
	return result;
}

//Time Complexity: O(n)
//Space Complexity: O(n)

//Problem Link: https://leetcode.com/problems/two-sum/