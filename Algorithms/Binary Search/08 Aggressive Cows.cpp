//AGGRESSIVE COWS

//Maximise minimum distance between any two cows

bool isPossible(int dist[], int n, int currDist, totalCows){
    int cowCount = 1, lastCowPos = dist[0];
    for(int i=1; i<n; i++)
        if(dist[i] - lastCowPos >= currDist){
            cowCount++;
            lastCowPos = dist[i];
        }
    return cowCount >= totalCows;
}

int aggressiveCows(int dist[], int n, int totalCows){
    sort(dist, dist + n);
    int low = 1, high = dist[n-1] - dist[0], mid, currDist;
    while(low <= high){
        mid = low + (high - low)/2;
        currDist = mid;
        if(isPossible(dist, n, currDist, totalCows))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

//Time complexity: O(n * log(d))        -> d = distance between first and last position
//Space complexity: O(1)

//Problem link: https://www.spoj.com/problems/AGGRCOW/