//STOCK BUY AND SELL

//BUYING AND SELLING ONE TIME ONLY

int maxProfit(vector<int>& prices) {
    int arr_size = prices.size();
    int currentBuyDay = 0, buyDay = 0, sellDay = 0, maxProfit = 0, profitForSellingToday;
    for(int i=0; i<arr_size; i++){
    	if(prices[currentBuyDay] > prices[i])
    		currentBuyDay = i;
    	profitForSellingToday = prices[i] - prices[currentBuyDay];
    	if(profitForSellingToday > maxProfit){
    		maxProfit = profitForSellingToday;
            buyDay = currentBuyDay;
    		sellDay = i;
    	}
    }
    return maxProfit;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/********************************************************************************************/

//BUYING AND SELLING MULTIPLE TIMES

int maxProfit(vector<int>& prices) {
    int maxProfit = 0, n = prices.size(), i = 0, currentBuyDay, currentSellDay;
    while(i < n){
        while(i < n-1){
            if( prices[i] < prices[i+1] )
                break;
            i++;
        }
        currentBuyDay = i;

        while(i < n-1){
            if( prices[i] > prices[i+1] )
                break;
            i++;
        }
        currentSellDay = i;
        maxProfit += prices[currentSellDay] - prices[currentBuyDay];

        if(i == n-1)
            i++;
    }
    return maxProfit;
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/********************************************************************************************/

//Try reading different variations of this problem.
//https://www.geeksforgeeks.org/best-time-to-buy-and-sell-stock/