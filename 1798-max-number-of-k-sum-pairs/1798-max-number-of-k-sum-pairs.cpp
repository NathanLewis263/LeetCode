class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        int ops = 0;
        while (left<right){
            if (nums[left] + nums[right] < k){
                left++;
            } else if (nums[left] + nums[right] > k) {
                right--;
            } else {
                ops++;
                left++;
                right--;
            }

        }
        return ops;
    }
};