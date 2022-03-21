//FIND Nth ROOT OF M

double power(double a, int n){
    double res = 1.0;
    for(int i=0; i<n; i++)
        res *= a;
    return res;
}

int NthRoot(int n, double m)
{
    // If x lies in the range [0, 1) then we set the lower limit low = x and upper limit high = 1, 
    // because for this range of numbers the nth root is always greater than the given number 
    // and can never exceed 1.
    double low = 0, high = m;
    if(0 <= m and m <= 1)
        low = m, high = 1;
    double absoluteError = 1e-6;
    while(high - low > absoluteError){
        double mid = low + (high - low)/2;
        if(power(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    double NthRoot = low;
    return NthRoot;
}

//Time complexity: O(n * log(m * (10^absErr)))
//Space complexity: O(1)

//Problem link: https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1/#