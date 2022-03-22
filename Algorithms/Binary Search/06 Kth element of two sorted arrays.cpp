//Kth ELEMENT OF TWO SORTED ARRAYS

int kthElement(int arr[], int brr[], int m, int n, int k)
{
    if(m > n)
        return kthElement(brr, arr, n, m, k);
    int low = max(0, k - n), high = min(k, m), cutArr, cutBrr, lArr, lBrr, rArr, rBrr;
    int kthElement = 0;
    while(low <= high){
        cutArr = low + (high-low)/2;
        cutBrr = k - cutArr;
        lArr = (cutArr == 0) ? INT_MIN : arr[cutArr - 1];
        lBrr = (cutBrr == 0) ? INT_MIN : brr[cutBrr - 1];
        rArr = (cutArr == m) ? INT_MAX : arr[cutArr];
        rBrr = (cutBrr == n) ? INT_MAX : brr[cutBrr];

        if(lArr <= rBrr and lBrr <= rArr){
            kthElement = max(lArr, lBrr);
            break;
        }
        else if(lArr > rBrr)
            high = cutArr - 1;
        else
            low = cutArr + 1;
    }
    return kthElement;
}

//Time complexity: O(log(min(m,n)))
//Space complexity: O(1)
//Problem link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1