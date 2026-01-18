//question 121
// 121. Best Time to Buy and Sell Stock
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104



//solution

int maxProfit(int* prices, int pricesSize) {
    int max=0;
    // int count = 0;
    // int i = 0;
    // int j = 1;
    // while(i<pricesSize){
    //     while(j<pricesSize){
    //         int diff=prices[j]-prices[i];
    //         if (diff>max){
    //             max=diff;
    //         }
    //         j++;
    //     }
    //     i++;
    // }
    // for(int i=0;i<pricesSize;i++){
    //     for(int j=i+1;j<pricesSize;j++){
    //         int diff=prices[j]-prices[i];
    //         if (diff>max){
    //             max=diff;
    //         }
    //     }
    // }
    // return max;
    
    int minBuy=10000;

    for(int i=0;i<pricesSize;i++){
        int profit = prices[i] - minBuy;
        if(max<profit){
            max= profit;
        }
        if(prices[i]<=minBuy){
            minBuy=prices[i];
        } 
    }
    return max;
}