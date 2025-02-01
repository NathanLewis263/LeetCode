class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // unordered_map<int, int> hash;
        // for (int i = 0; i < nums.size(); i++) {
        //     hash[nums[i]] = i;
        // }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = find(nums.begin()+i+1,nums.end(),complement);
            if ( it != nums.end()) {
                int index = it - nums.begin();
                return {i, index};
            }
        }
        return {};
    }
};