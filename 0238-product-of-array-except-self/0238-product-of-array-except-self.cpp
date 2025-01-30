class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers(nums.size(),1);
        int prefix = 1;
        for (int i = 0;i<nums.size();i++){
            answers[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = nums.size()-1;i>=0;i--){
            answers[i] *= postfix;
            postfix *= nums[i];
        }
        return answers;
    }
};