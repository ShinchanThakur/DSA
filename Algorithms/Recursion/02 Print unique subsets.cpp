// PRINT ALL UNIQUE SUBSETS

// USING SET DATASTRUCTURE

void recursionHelperForSetSolution(vector<int> &nums, int index, vector<int> &subset, set<vector<int>> &uniqueSubsets)
{
    if (index == nums.size())
    {
        uniqueSubsets.insert(subset);
        return;
    }
    // take current element
    subset.push_back(nums[index]);
    recursionHelperForSetSolution(nums, index + 1, subset, uniqueSubsets);
    // do not take current element
    subset.pop_back();
    recursionHelperForSetSolution(nums, index + 1, subset, uniqueSubsets);
}

vector<vector<int>> uniqueUsingSet(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> uniqueSubsets;
    vector<int> subset;
    int index = 0;
    recursionHelperForSetSolution(nums, index, subset, uniqueSubsets);
    vector<vector<int>> uniqueSubsetsVector;
    for (vector<int> uniqueSubset : uniqueSubsets)
        uniqueSubsetsVector.push_back(uniqueSubset);
    return uniqueSubsetsVector;
}

// Time complexity: O(2^n klog(x))   k->average size of subsets      x->size of set
// Space complexity: 2*O(2^n k)

/*******************************************************************************************************************/

// OPTIMAL -> Without using set

void recursionHelperForVectorSolution(vector<int> &nums, int index, vector<int> &subset, vector<vector<int>> &uniqueSubsets)
{
    uniqueSubsets.push_back(subset);
    for (int i = index; i < nums.size(); i++)
    {
        // ignoring if the element is duplicate (except the first one)
        if (i != index && nums[i] == nums[i - 1])
            continue;
        // take current element in subset
        subset.push_back(nums[i]);
        recursionHelperForVectorSolution(nums, i + 1, subset, uniqueSubsets);
        // do not take current element in subset
        subset.pop_back();
    }
}
vector<vector<int>> uniqueWithoutUsingSet(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> uniqueSubsets;
    vector<int> subset;
    int index = 0;
    recursionHelperForVectorSolution(nums, index, subset, uniqueSubsets);
    return uniqueSubsets;
}

// Time complexity: O(2^n k)
// Space complexity: O(2^n k)

// Problem Link: https://leetcode.com/problems/subsets-ii/
