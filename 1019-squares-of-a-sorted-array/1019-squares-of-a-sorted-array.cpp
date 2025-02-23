class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());
        int n = right;
        while (left<=right){
            int square;
            if (abs(nums[left])<abs(nums[right])){
                square = nums[right];
                right--;
            } else {
                square = nums[left];
                left++;
            }
            ans[n] = square * square;
            n--;
        }
        return ans;
    }
};