//PRINT SUMS OF ALL SUBSETS OF AN ARRAY

void generateSubsets(vector<int> &arr, vector<int> &subsetSums, int n, int ind, int sum){
    if(ind == n){
        subsetSums.push_back(sum);
        return;
    }
    generateSubsets(arr, subsetSums, n, ind + 1, sum);      //not taking element at index ind
    generateSubsets(arr, subsetSums, n, ind + 1, sum + arr[ind]);       //taking it
}

vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> subsetSums;
    int ind = 0, sum = 0;
    generateSubsets(arr, subsetSums, n, ind, sum);
    sort(subsetSums.begin(), subsetSums.end());
    return subsetSums;
}

//Time complexity: O(2^n log(2^n))
//Space complexity: O(2^n)

//Problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#