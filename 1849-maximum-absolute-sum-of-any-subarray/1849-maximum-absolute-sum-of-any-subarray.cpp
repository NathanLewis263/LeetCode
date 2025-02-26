class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        int minPrefix = 0;
        int maxPrefix = 0;
        int maxAbsSum = 0;
        for (int i = 0;i<n;i++){
            prefix += nums[i];  // Compute prefix sum
            minPrefix = min(minPrefix, prefix);  // Track minimum prefix sum
            maxPrefix = max(maxPrefix, prefix);  // Track maximum prefix sum
            maxAbsSum = max(maxAbsSum, abs(maxPrefix - minPrefix)); // Compute max abs diff
        }
        return maxAbsSum;
    }
};