//FIND MEDIAN OF TWO SORTED ARRAYS

double findMedianSortedArrays(vector<int>& arr, vector<int>& brr) {
    int m = arr.size(), n = brr.size();
    if(m > n)
        return findMedianSortedArrays(brr, arr);
    int low = 0, high = m, numsOnLeftOfMedian = (m + n + 1)/2, cutArr, cutBrr, lArr, lBrr, rArr, rBrr;
    double median = 0;
    while(low <= high){
        cutArr = low + (high-low)/2;
        cutBrr = numsOnLeftOfMedian - cutArr;
        lArr = (cutArr == 0) ? INT_MIN : arr[cutArr - 1];
        lBrr = (cutBrr == 0) ? INT_MIN : brr[cutBrr - 1];
        rArr = (cutArr == m) ? INT_MAX : arr[cutArr];
        rBrr = (cutBrr == n) ? INT_MAX : brr[cutBrr];

        if(lArr <= rBrr and lBrr <= rArr){
            if((m+n)%2)
                median = max(lArr, lBrr);
            else
                median = (max(lArr, lBrr) + min(rArr, rBrr)) / 2.0;
            break;
        }
        else if(lArr > rBrr)
            high = cutArr - 1;
        else
            low = cutArr + 1;
    }
    return median;
}

//Time complexity: O(log(min(m,n)))     ->Binary search in smaller size array
//Space complexity: O(1)
//Problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/