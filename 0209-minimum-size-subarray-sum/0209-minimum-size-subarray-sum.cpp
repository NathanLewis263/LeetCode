class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimal = INT_MAX;
        int total = 0;
        for (int i = 0, left = 0;i<nums.size();i++){
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