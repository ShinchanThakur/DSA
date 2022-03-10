//FRACTIONAL KNAPSACK

struct Item{
    int value;
    int weight;
};

static bool comparator(Item a, Item b){
    return ((double)a.value)/a.weight > ((double)b.value)/b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, comparator);
    double totalValue = 0, totalWt = 0;
    for(int i=0; i<n; i++){
        if(totalWt + arr[i].weight <= W){
            totalWt += arr[i].weight;
            totalValue += arr[i].value;
        }
        else{
            int remainingWt = W - totalWt;
            totalValue += ((double)arr[i].value)/arr[i].weight * remainingWt;
            break;
        }
    }
    return totalValue;
}

//Time complexity: O(nlogn)
//Space complexity: O(1)

//Problem Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1