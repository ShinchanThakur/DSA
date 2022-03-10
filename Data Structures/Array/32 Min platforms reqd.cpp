//FIND MINIMUM NUMBER OF PLATFORMS REQUIRED FOR THE FOLLOWING TRAINS

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);   sort(dep, dep+n);
    int minPlatforms = 0, currPlatforms = 0, i = 0, j = 0;
    while(i<n and j<n){
        if(arr[i] <= dep[j])   //train came
            currPlatforms++, i++;
        else                    //train left
            currPlatforms--, j++;
        minPlatforms = max(currPlatforms, minPlatforms);
    }
    return minPlatforms;
}

//Time complexity: O(nlogn)
//Space complexity: O(1)

//Problem Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#