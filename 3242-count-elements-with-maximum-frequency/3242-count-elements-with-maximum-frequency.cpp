class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxFreak = 0;
        for (auto& num : nums){
            maxFreak = max(maxFreak,++map[num]);
        }
        int total = 0;
        for (auto& pair : map){
            if (pair.second == maxFreak){
                total+=maxFreak;
            }
        }
        return total;
    }
};