//PRINT ALL UNIQUE COMBINATIONS WITH GIVEN SUM
//Elements can be chosen only once

void checkAllPossibleCombinations(vector<int> &arr, vector<vector<int>> &uniqueCombinations, vector<int> &subset, int target, int ind){
    if(target == 0){
        uniqueCombinations.push_back(subset);
        return;
    }
    for(int i=ind; i<arr.size(); i++){
        if(i != ind and arr[i] == arr[i-1])     continue;
        if(arr[i] <= target){
            subset.push_back(arr[i]);
            checkAllPossibleCombinations(arr, uniqueCombinations, subset, target-arr[i], i+1);
            subset.pop_back();
        }
        else
            break;
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int ind = 0;
    vector<vector<int>> uniqueCombinations;
    vector<int> subset;
    checkAllPossibleCombinations(arr, uniqueCombinations, subset, target, ind);
    return uniqueCombinations;
}

//Time complexity: O(2^n k)     k->average length of combination
//                                k is multiplied here as it takes O(k) to add it to final answer
//Space complexity: O(k*x)      x->number of unique combinations

//Problem link: https://leetcode.com/problems/combination-sum-ii/