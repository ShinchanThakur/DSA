// 3 SUM PROBLEM -> Return unique triplets with given sum

vector<vector<int>> threeSumProblem(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> tripletsWithTargetSum;
    for(int i=0; i<n-2; i++){
        if(i > 0 and arr[i] == arr[i-1])    continue;
        int low = i+1, high = n-1;
        while(low < high){
            int sum = arr[i] + arr[low] + arr[high];
            if(sum < target)
                low++;
            else if(sum > target)
                high--;
            else{
                vector<int> triplet = {arr[i], arr[low], arr[high]};
                tripletsWithTargetSum.push_back(triplet);
                while(low < high and arr[low] == arr[low+1])    low++;
                while(low < high and arr[high] == arr[high-1])  high--;
                low++;
                high--;
            }
        }
    }
    return tripletsWithTargetSum;
}

//Time complexity: O(n^2)
//Space complexity: O(1)

//Problem Link: https://leetcode.com/problems/3sum/