class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int prefix_sum = 0, max_length = 0;

        mp[0] = -1; // Handle case where the subarray starts from index 0

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += (nums[i] == 0) ? -1 : 1; // Convert 0s to -1

            if (mp.find(prefix_sum) != mp.end()) {
                max_length = max(max_length, i - mp[prefix_sum]);  
            } else {
                mp[prefix_sum] = i; // Store first occurrence
            }
        }
        return max_length;
    }
};