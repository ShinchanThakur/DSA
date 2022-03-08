//FIND DUPLICATE IN ARRAY
//Array of size n+1
//Elements from 1 to n
//One element is duplicate

//USING LINKED LIST CYCLE METHOD

int findDuplicate(vector<int>& arr) {
	int arr_size = arr.size();
	int slow = arr[0], fast = arr[0];
	do{
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while(slow != fast);
	fast = arr[0];
	while(slow != fast){
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
//				 https://leetcode.com/problems/single-number/
//				 https://leetcode.com/problems/missing-number/
//				 https://leetcode.com/problems/set-mismatch/