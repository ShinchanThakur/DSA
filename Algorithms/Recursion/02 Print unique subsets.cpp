//PRINT ALL UNIQUE SUBSETS

//USING SET DATASTRUCTURE

void generateAllSubsets(vector<int> &arr, set<vector<int>> &sett, vector<int> subset, int ind){
    if(ind == arr.size()){
        sort(subset.begin(), subset.end());
        sett.insert(subset);
        return;
    }
    subset.push_back(arr[ind]);
    generateAllSubsets(arr, sett, subset, ind+1);
    subset.pop_back();
    generateAllSubsets(arr, sett, subset, ind+1);
}

vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    vector<vector<int>> uniqueSubsets;
    set<vector<int>> sett;
    vector<int> subset;
    int ind = 0;
    generateAllSubsets(arr, sett, subset, ind);
    for(vector<int> subset: sett)
        uniqueSubsets.push_back(subset);
    return uniqueSubsets;
}

//Time complexity: O(2^n klog(x))   k->average size of subsets      x->size of set
//Space complexity: 2*O(2^n k)        

/*******************************************************************************************************************/

//OPTIMAL -> Without using set

void generateAllSubsets(vector<int> &arr, vector<vector<int>> &uniqueSubsets, vector<int> &subset, int ind){
    uniqueSubsets.push_back(subset);
    for(int i = ind; i<arr.size(); i++){
        if(i != ind and arr[i] == arr[i-1])     continue;
        subset.push_back(arr[i]);
        generateAllSubsets(arr, uniqueSubsets, subset, i+1);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    vector<vector<int>> uniqueSubsets;
    vector<int> subset;
    sort(arr.begin(), arr.end());
    int ind = 0;
    generateAllSubsets(arr, uniqueSubsets, subset, ind);
    return uniqueSubsets;
}

//Time complexity: O(2^n k)
//Space complexity: O(2^n k)

//Problem Link: https://leetcode.com/problems/subsets-ii/
