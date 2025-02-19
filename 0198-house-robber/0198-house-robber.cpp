class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = 0, prev1 = 0; 

        for (int num : nums) {
            int curr = max(prev1, num + prev2);  // Take or skip
            prev2 = prev1;  // Move prev2 forward
            prev1 = curr;   // Move prev1 forward
        }

        return prev1;
    }
};
