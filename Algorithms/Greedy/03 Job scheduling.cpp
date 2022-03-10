//FIND MAXIMUM PROFIT THAT CAN BE OBTAINED WITH FOLLOWING JOBS AND THEIR DEADLINES
//EACH JOB TAKES ONE UNIT OF TIME TO COMPLETE 

struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool comparator(Job a, Job b){
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr+n, comparator);
    int maxDeadline = arr[0].dead;
    for(int i=1; i<n; i++)
        maxDeadline = max(maxDeadline, arr[i].dead);
    int slot[maxDeadline+1];
    for(int i=0; i<maxDeadline+1; i++)
        slot[i] = -1;
    int maxProfit = 0, jobCount = 0;
    for(int i=0; i<n; i++)
        for(int j=arr[i].dead; j>0; j--)
            if(slot[j] == -1){
                slot[j] = i;
                maxProfit += arr[i].profit;
                jobCount++;
                break;
            }
    return {jobCount, maxProfit};
} 

//Time complexity: O(n*m)       m -> max(deadlines)
//Space complexity: O(m)

//Problem Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

/*****************************************************************************************************************/

// For better approaches, read the following links:
// https://www.geeksforgeeks.org/weighted-job-scheduling/
// https://www.cdn.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/