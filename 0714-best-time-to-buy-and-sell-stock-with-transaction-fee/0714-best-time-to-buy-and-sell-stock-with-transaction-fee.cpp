class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int cash = 0;
        int hold = -prices[0]; //-price[0] cuz we dont have any cash to buy stocks on day 0 hence -ve

        for (int i = 1; i < n; i++) {
            cash = max(cash, hold + prices[i] - fee); // Sell stock
            hold = max(hold, cash - prices[i]);       // Buy stock
        }
        return  cash;
    }
};