class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int currhold = -prices[0], totalmoney = 0;
        for(int i=1;i<prices.size();i++){
            int prevhold = currhold, prevmoney = totalmoney;
            currhold = max(prevhold, prevmoney-prices[i]);
            totalmoney = max(prevmoney, prevhold + prices[i] - fee);
        }
        return totalmoney;  
    }
};
