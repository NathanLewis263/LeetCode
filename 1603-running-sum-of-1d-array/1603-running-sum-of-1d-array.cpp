class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix.at(0) = nums.at(0);
        for (int i = 1;i<n;i++){
            prefix.at(i) = prefix.at(i-1) + nums.at(i);
        }
        return prefix;
    }
};