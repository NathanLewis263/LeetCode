class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefix;
        prefix[0] = 1;
        int total = 0;
        int ans = 0;
        for (int i = 0;i<nums.size();i++){
            total+=nums[i];
            if (prefix[total-goal]){
                ans+=prefix[total-goal];
            }
            prefix[total]++;
        }
        return ans;
    }
};