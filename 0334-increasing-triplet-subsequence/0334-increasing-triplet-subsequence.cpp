class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int firstNum = INT_MAX;
        int secondNum = INT_MAX;
        for (int n : nums){
            if (n<=firstNum){
                firstNum = n;
            } else if (n<=secondNum){
                secondNum = n;
            } else {
                return true;
            }
        }
        return false;
    }
};