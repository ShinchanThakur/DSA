//GET Nth PEMUTATION

string getPermutation(int n, int k) {
    vector<int> arr(n);
    int nMinusOnefact = 1;
    for(int i=1; i<n; i++){
        arr[i-1] = i;
        nMinusOnefact *= i;
    }
    string kthPermutation = "";
    arr[n-1] = n;
    k = k-1;
    while(true){
        kthPermutation += to_string(arr[k / nMinusOnefact]);
        arr.erase(arr.begin() + k / nMinusOnefact);
        if(arr.size() == 0)
            break;
        k %= nMinusOnefact;
        nMinusOnefact /= arr.size();
    }
    return kthPermutation;
}

//Time complexity: O(n*n)       -> n->placing n numbers in n places
//                                -> n->removing a number everytime from vector
//Space complexity: O(n)

//Problem link: https://leetcode.com/problems/permutation-sequence/