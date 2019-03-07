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

March 7th 2019
O(N2) Solution Brute Force

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }
};

O(N) Solution Peak - Valley Hint

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0; i<n; i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

