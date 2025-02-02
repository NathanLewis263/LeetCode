class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftSum = 0;
        for (int num : nums){
            sum += num;
        }
        for (int i = 0;i<nums.size();i++){
            int rightSum = sum - leftSum - nums.at(i);
            if (leftSum == rightSum){
                return i;
            }
            leftSum += nums.at(i);
        }
        return -1;
    }
};