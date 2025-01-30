class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }
        
        vector<vector<int>> mapToVector;
        for (auto& pair : mp) {
            mapToVector.push_back({pair.first, pair.second});
        }

        sort(mapToVector.begin(),mapToVector.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
            });
        vector<int> ans;

        for (int i=0;i<k;i++){
            ans.push_back(mapToVector[i][0]);
        }
        return ans;
    }
};