//PRINT ALL PERMUTATIONS OF A GIVEN ARRAY
//No duplicates are there

//BACKTRACKING

void getAllPermutations(vector<int> &arr, vector<vector<int>> &allPermutations, int begin){
    if(begin == arr.size()){
        allPermutations.push_back(arr);
        return;
    }
    for(int i=begin; i<arr.size(); i++){
        swap(arr[begin], arr[i]);
        getAllPermutations(arr, allPermutations, begin+1);
        swap(arr[begin], arr[i]);
    }
}

vector<vector<int>> permute(vector<int>& arr) {
    vector<vector<int>> allPermutations;
    int begin = 0;
    getAllPermutations(arr, allPermutations, begin);
    return allPermutations;
}

/*****************************************************************************************************************/

//RECURSION

void getAllPermutations(vector<int> &arr, vector<int> &permutation, vector<vector<int>> &allPermutations, vector<int> &visited){
    if(permutation.size() == arr.size()){
        allPermutations.push_back(permutation);
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(!visited[i]){
            permutation.push_back(arr[i]);
            visited[i] = 1;
            getAllPermutations(arr, permutation, allPermutations, visited);
            visited[i] = 0;
            permutation.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& arr) {
    int ind = 0;
    vector<int> visited(arr.size(), 0);
    vector<int> permutation;
    vector<vector<int>> allPermutations;
    getAllPermutations(arr, permutation, allPermutations, visited);
    return allPermutations;
}

//Time complexity: O(n*n!)      ->n for making a copy and storing it in result
//Space complexity: O(n*n!)

//Problem link: https://leetcode.com/problems/permutations/

//Learn the one where duplicates are also present