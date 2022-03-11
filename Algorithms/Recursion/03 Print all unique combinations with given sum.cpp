//PRINT ALL UNIQUE COMBINATIONS WITH GIVEN SUM
//Elements can be chosen infinite times

void checkAllPossibleCombinations(vector<int> &arr, vector<vector<int>> &uniqueCombinations, vector<int> &subset, int target, int ind){
    if(ind == arr.size()){
        if(target == 0)
            uniqueCombinations.push_back(subset);
        return;
    }
    //include arr[i]
    if(arr[ind] <= target){
        subset.push_back(arr[ind]);
        checkAllPossibleCombinations(arr, uniqueCombinations, subset, target-arr[ind], ind);    //ind is not incremented
                                                                                                //because a number can be chosen infinite times
        subset.pop_back();
    }
    checkAllPossibleCombinations(arr, uniqueCombinations, subset, target, ind+1);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> uniqueCombinations;
    int ind = 0;
    vector<int> subset;
    checkAllPossibleCombinations(arr, uniqueCombinations, subset, target, ind);
    return uniqueCombinations;
}

//Time complexity: O(2^t k)     t->target       k->average length of combination
                                // To understand 2^t instead of 2^n, consider the case with target = 10 and arr[i] = 1
                                // here 10 times we have the option to choose or reject 1
                                // -> 2^10
//Space complexity: O(k*x)      x->number of unique combinations

//Problem link: https://leetcode.com/problems/combination-sum/