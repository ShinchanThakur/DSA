//SEARCH ELEMENT IN A ROTATED SORTED ARRAY

int search(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1, mid;
    while(low <= high){
        mid = low + ((high - low)>>1);
        if(arr[mid] == target)
            return mid;
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target and target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(arr[mid] <= target and target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

//Time complexity: O(logn)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/