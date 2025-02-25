class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> map;
        for (auto match : matches){
            map[match[0]];
            map[match[1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto pair : map){
            if (pair.second == 0){
                ans[0].push_back(pair.first);
            } else if (pair.second == 1){
                ans[1].push_back(pair.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};