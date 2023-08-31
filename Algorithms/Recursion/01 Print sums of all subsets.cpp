// PRINT SUMS OF ALL SUBSETS OF AN ARRAY

void subsetSumsRecursive(vector<int> &subsetSum, int currentIndex, vector<int> &arr, int arrSize, int currentSum)
{
    if (currentIndex == arrSize)
    {
        subsetSum.push_back(currentSum);
        return;
    }
    // take current element
    subsetSumsRecursive(subsetSum, currentIndex + 1, arr, arrSize, currentSum + arr[currentIndex]);
    // do not take current element
    subsetSumsRecursive(subsetSum, currentIndex + 1, arr, arrSize, currentSum);
}

vector<int> subsetSums(vector<int> arr, int arrSize)
{
    vector<int> subsetSum;
    int currentIndex = 0, currentSum = 0;
    subsetSumsRecursive(subsetSum, currentIndex, arr, arrSize, currentSum);
    return subsetSum;
}

// Time complexity: O(2^n log(2^n))
// Space complexity: O(2^n)

// Problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#