//Kind of DP problem
//always think of options. at some point in day you can either be in possession of stock or not
//not meaning you are selling the stock which you had or just skipping today
//total money 
//to remember easily we can note that if stock_in_hold is initialized to -prices[0] then while calculating cash we need to add the next value in prices

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int money = 0;
        int stock_in_hold = -prices[0];
        for(int i=1;i<n;i++)
        {
            money = max(money,stock_in_hold + prices[i] - fee);
            stock_in_hold = max(stock_in_hold,money - prices[i]);
        }
        return money;
    }
};