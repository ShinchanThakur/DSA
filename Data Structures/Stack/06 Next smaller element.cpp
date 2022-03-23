//NEXT SMALLER ELEMENT

vector<int> nextSmallerElement(vector<int> arr){
    int n = arr.size();
    stack<pair<int, int>> s;
    vector<int> nse(n, -1);
    for(int i=0; i<n; i++){
        while(s.size() and s.top().first > arr[i]){
            nse[s.top().second] = arr[i];
            s.pop();
        }
        s.push({arr[i], i});
    }
    return nse;
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/