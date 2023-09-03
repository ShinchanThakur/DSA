// FIND Nth ROOT OF M

double power(double a, int n)
{
    double res = 1.0;
    for (int i = 0; i < n; i++)
        res *= a;
    return res;
}

int NthRoot(int n, double m)
{
    // If x lies in the range [0, 1) then we set the lower limit low = x and upper limit high = 1,
    // because for this range of numbers the nth root is always greater than the given number
    // and can never exceed 1.
    double low = 0, high = m;
    if (0 <= m and m <= 1)
        low = m, high = 1;
    double absoluteError = 1e-6;
    while (high - low > absoluteError)
    {
        double mid = low + (high - low) / 2;
        if (power(mid, n) < m)
            low = mid;
        else
            high = mid;
    }
    double NthRoot = low;
    return NthRoot;
}

// Time complexity: O(n * log(m * (10^absErr)))
// Space complexity: O(1)

// Problem link: https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1/#

// SIMPLE SOLUTION

int modifiedBinaryExponentiation(int n, int exponent, int upperLimit)
{
    long long int ans = 1;
    long long int longN = n;

    while (exponent != 0)
    {
        if (exponent % 2)
        {
            ans *= longN;
            exponent--;
        }
        else
        {
            longN *= longN;
            exponent /= 2;
        }
        if (ans > upperLimit)
            return -1;
        if (longN > upperLimit)
            return -1;
    }
    return ans;
}

int findNthRootUsingLinearSearch(int index, int radicand)
{
    int nthRoot = -1;
    for (int i = 1; i <= radicand; i++)
    {
        int iPowerIndex = modifiedBinaryExponentiation(i, index, radicand);
        if (iPowerIndex == -1)
            break;
        if (iPowerIndex == radicand)
        {
            nthRoot = i;
            break;
        }
    }
    return nthRoot;
}

int findNthRootUsingBinarySearch(int index, int radicand)
{
    int nthRoot = -1;
    int low = 1, high = radicand;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midPowerIndex = modifiedBinaryExponentiation(mid, index, radicand);
        if (midPowerIndex == radicand)
        {
            nthRoot = mid;
            break;
        }
        else if (midPowerIndex == -1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return nthRoot;
}

int NthRoot(int index, int radicand)
{
    return findNthRootUsingBinarySearch(index, radicand);
}

// Problem link: https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website