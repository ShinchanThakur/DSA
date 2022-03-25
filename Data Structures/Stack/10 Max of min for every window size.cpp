//MAX OF MIN FOR EVERY WINDOW SIZE

void getLeftSmaller(vector<int> &leftSmaller, int arr[], int n){
    stack<int> s;
    for(int i=0; i<n; i++){
        while(s.size() and arr[s.top()] >= arr[i])
            s.pop();
        if(s.size())
            leftSmaller[i] = s.top();

        s.push(i);
    }
}

void getRightSmaller(vector<int> &rightSmaller, int arr[], int n){
    stack<int> s;
    for(int i=n-1; i>=0; i--){
        while(s.size() and arr[s.top()] >= arr[i])
            s.pop();
        if(s.size())
            rightSmaller[i] = s.top();

        s.push(i);
    }
}

vector <int> maxOfMin(int arr[], int n)
{
    vector<int> leftSmaller(n, -1), rightSmaller(n, n), ans(n, 0);
    getLeftSmaller(leftSmaller, arr, n);
    getRightSmaller(rightSmaller, arr, n);

    for(int i=0; i<n; i++){
        int len = (rightSmaller[i] - 1) - (leftSmaller[i] + 1) + 1;
        //We know that arr[i] is the minimum element in the range (left + 1) to (right - 1)
        //Therefore it can be the maximum of minimums in range of length len
        ans[len - 1] = max(ans[len - 1], arr[i]);
        //storing answer of len in len-1 because of 0 based indexing
    }

    for(int i=n-2; i>=0; i--)
        ans[i] = max(ans[i], ans[i+1]);
    //Filling values for remaining ranges

    return ans;
}

//Time complexity: O(n)
//Space complexity: O(n)

//Problem link: https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/