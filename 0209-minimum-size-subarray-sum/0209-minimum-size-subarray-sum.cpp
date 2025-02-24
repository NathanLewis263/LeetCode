class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimal = INT_MAX;
        int left = 0;
        int total = 0;
        int n = nums.size();
        for (int i = 0;i<n;i++){
            total += nums[i];
            while (total>=target){
                minimal = min(minimal,i-left+1);
                total -= nums[left];
                left++;
            }
        }
        return minimal == INT_MAX ? 0 : minimal;
    }
};