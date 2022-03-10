//REMOVE DUPLICATES FROM ARRAY IN PLACE

int removeDuplicates(vector<int>& arr) {
    int i=0;
    // arr[i] = arr[0];
    for(int j=1; j<arr.size(); j++)
        if(arr[i] != arr[j])
            arr[++i] = arr[j];
    return i+1;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/