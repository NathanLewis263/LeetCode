class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0;i<k;i++){
            sum+=nums.at(i);
        }
        double maxAvg = sum/(double)k;
        for (int i = k;i<n;i++){
            sum+=nums.at(i);
            sum-=nums.at(i-k);
            maxAvg = max(maxAvg,sum/(double)k);
        }
        return maxAvg;
    }
};