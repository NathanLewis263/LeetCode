class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int numFlipped = 0;
        int left = 0;
        for (int right = 0; right < nums.size();right++){
            if (nums[right] == 0){
                numFlipped++;
            } 
            while (numFlipped>k){
                if (nums[left]==0){
                    numFlipped--;
                }
                left++;
            }
            maxLength = max(maxLength,right-left+1);
        }
        return maxLength;
    }
}; 