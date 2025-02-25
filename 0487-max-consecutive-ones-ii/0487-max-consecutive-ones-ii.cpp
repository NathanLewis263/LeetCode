class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zero = 0;
        int len = 0;
        int left = 0;
        for (int right = 0;right<nums.size();right++){
            if (nums[right] == 0){
                zero++;
            }
            while (zero > 1) { // Only allow one zero
                if (nums[left] == 0) zero--;
                left++;
            }
            len = max(len, right-left+1);
        }
        return len;
    }
};