class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int minVal = 0;
        for (int i = 0;i<n;i++){
            total += nums.at(i);
            minVal = min(minVal, total);
        }
        return -minVal+1;
    }
};