class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int min = prices[0];
        int max_profit = 0;
        for(auto it=prices.begin()+1;it!=prices.end();it++)
        {
            if(*it < min)
                min = *it;
            else if(*it - min > max_profit)
                max_profit = *it - min;
        }
        return max_profit;
    }
};
