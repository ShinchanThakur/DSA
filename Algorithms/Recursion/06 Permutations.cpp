//PRINT ALL PERMUTATIONS OF A GIVEN ARRAY
//No duplicates are there

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

//Time complexity: O(n*n!)      ->n for making a copy and storing it in result
//Space complexity: O(n*n!)

//Problem link: https://leetcode.com/problems/permutations/

//Learn the one where duplicates are also present