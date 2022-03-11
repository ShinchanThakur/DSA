//FIND MINIMUM NUMBER OF COINS TO MAKE THE CHANGE

//RECURSIVE

int minCoins(int coins[], int n, int money) 
{ 
    if(money == 0)      return 0;
    int totalCoins = INT_MAX;
    for(int i=0; i<n; i++){
        int coin = coins[i];
        if(coin <= money){
            int subTotalCoins = minCoins(coins, n, money - coin);
            if(subTotalCoins != INT_MAX)
                totalCoins = min(totalCoins, subTotalCoins + 1);
        }
    }
    return totalCoins;
}

//Time complexity: exponential
//Space complexity: O(1) 		(if recursion stack is considered, then analyse it)

//Problem Link: https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/

/********************************************************************************************************************/

//DP

int minCoins(int coins[], int n, int money) 
{ 
    int minCoins[money+1];
    minCoins[0] = 0;      //Base case
    for(int i=1; i<=money; i++)
        minCoins[i] = INT_MAX;
    for(int currMoney = 1; currMoney <= money; currMoney++){
        for(int i=0; i<n; i++){
            if(coins[i] <= currMoney and minCoins[currMoney - coins[i]] != INT_MAX)
                minCoins[currMoney] = min(minCoins[currMoney], minCoins[currMoney - coins[i]] + 1);
        }
    }
    if(minCoins[money] == INT_MAX)
        return -1;
    return minCoins[money];
}

//Time complexity: O(n*m)		(m->size of coins array			n->money to change)
//Space complexity: O(n)