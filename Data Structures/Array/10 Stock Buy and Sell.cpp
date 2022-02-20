//STOCK BUY AND SELL

//SELLING AND BUYING ONE TIME ONLY

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

//Try reading different variations of this problem.