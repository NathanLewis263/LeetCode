class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers(nums.size(),1); 
        int prefix = 1;
        for (int i = 0;i<nums.size();i++){
            answers[i] = prefix; //[1,1,2,6] prefix
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = nums.size()-1;i>=0;i--){
            answers[i] *= postfix; //prefix<-[1,1,2,6] * [24,12,4,1]->postfix
            postfix *= nums[i];
        }
        return answers;
    }
};