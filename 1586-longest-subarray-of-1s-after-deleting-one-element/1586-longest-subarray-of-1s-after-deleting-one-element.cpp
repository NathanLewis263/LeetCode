class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int left = 0;
        int remove = 0;
        for (int right = 0; right < nums.size();right++){
            if (nums[right]!=1){
                remove++;
            }
            while (remove>1){
                if (nums[left]!=1){
                    remove--;
                }
                left++;
            }
        maxLen = max(maxLen,right-left);
        }
    return maxLen;
    }
};