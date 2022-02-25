//REVERSE AN ARRAY

//ITERATIVE
void reverseArrayIterative(int arr[], int size){
    int start = 0, end = size-1;
    while(start<end)
        swap(arr[start++], arr[end--]);
}

//RECURSIVE
void reverseArrayRecursive(int arr[], int start, int end){
    if(start>=end)
        return;
    swap(arr[start], arr[end]);
    reverseArrayRecursive(arr, start+1, end-1);
}

// TIME COMPLEXITY - O(n)
// SPACE COMPLEXITY - O(1)

//Problem Link - https://leetcode.com/problems/reverse-string/