//SEARCH SINGLE ELEMENT IN A SORTED ARRAY WITH ALL OTHER ELEMENTS APPEARING TWICE


/*
    array elements -> 1 1 2 2 3 4 4 5 5
    indexes        -> 0 1 2 3 4 5 6 7 8
    
    Left half(0-3)  -> first instance = even   second instance = odd
    Right half(5-8) -> first instance = odd    second instance = even

*/

int singleNonDuplicate(vector<int>& arr){
    if(arr.size() == 1)
        return arr[0];
    int low = 0, high = arr.size()-1, mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(mid % 2){
            if(arr[mid] == arr[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(arr[mid] != arr[mid + 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return arr[low];
}

//Time complexity: O(logn)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/