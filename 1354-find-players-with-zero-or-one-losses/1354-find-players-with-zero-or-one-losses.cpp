class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lossCount;
        for (auto& match : matches){
            lossCount[match[0]]; // Ensure winners exist in the map
            lossCount[match[1]]++; // Increment loss count for losers
        }
        vector<vector<int>> ans(2);
        for (auto& pair : lossCount){
            if (pair.second == 0){
                ans[0].push_back(pair.first); // Players with 0 losses
            } else if (pair.second == 1){
                ans[1].push_back(pair.first); // Players with 1 loss
            }
        }
        
        // Sort for increasing order
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};