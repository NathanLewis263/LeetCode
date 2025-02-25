class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        for (int i = 0;i<k;i++){
            map[nums[i]]++;
        }

        ans.push_back(map.size());
        for (int i = k;i<nums.size();i++){
            map[nums[i-k]]--;
            if (map[nums[i-k]]==0){
                map.erase(nums[i-k]);
            }
            map[nums[i]]++;
            ans.push_back(map.size());
        }
        return ans;
    };
};