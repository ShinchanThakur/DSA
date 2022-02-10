//MOORE'S VOTING ALGORITHM
//MAJORITY ELEMENT
//GREATER THAN N/2 TIMES

int majorityElement(vector<int>& nums){
	int count = 0, candidate;
	for(int num: nums){
		if(count == 0)
			candidate = num;
		if(num == candidate)
			count++;
		else
			count--;
	}
	return candidate;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/majority-element/

/*******************************************************************************************/
//EXTENDED MOORE'S VOTING ALGORITHM
//GREATER THAN N/3 TIMES

vector<int> majorityElements(vector<int>& nums){
	int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
	for(int num: nums){
		if(num == num1)
			count1++;
		else if(num == num2)
			count2++;
		else if(count1 == 0)
			num1 = num, count1 = 1;
		else if(count2 == 0)
			num2 = num, count2 = 1;
		else
			count1--, count2--;
	}
	vector<int> majorityElements;
	count1 = count2 = 0;
	for(int num: nums){
		if(num == num1)
			count1++;
		else if(num == num2)
			count2++;
	}
	int arr_size = nums.size();
	if(count1 > arr_size/3)
		majorityElements.push_back(num1);
	if(count2 > arr_size/3)
		majorityElements.push_back(num2);
	return majorityElements;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/majority-element-ii/