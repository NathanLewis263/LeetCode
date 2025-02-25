class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeroIndex = -1;
        int len = 0;
        int left = 0;
        for (int right = 0;right<nums.size();right++){
            if (nums[right] == 0){
                if (zeroIndex != -1){
                    left = zeroIndex + 1;
                }
                zeroIndex = right;
            }
            len = max(len, right-left+1);
        }
        return len;
    }
};