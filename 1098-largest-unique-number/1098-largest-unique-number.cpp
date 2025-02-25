class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxVal = -1;
        for (int& num : nums){
            map[num]++;
        }
        for (auto& pair : map){
            if (pair.second == 1){
                maxVal = max(maxVal,pair.first);
            }
        }
        return maxVal;
    }
};