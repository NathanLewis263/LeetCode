class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]){
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};