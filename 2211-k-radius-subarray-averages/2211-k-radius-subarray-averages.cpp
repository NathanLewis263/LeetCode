class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0){
            return nums;
        }
        int n = nums.size();
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1;i<n;i++){
             prefix[i] = prefix[i-1] + nums[i];
         }
        vector<int> avgs;
        int kSize = 2 * k + 1;

        for (int i = 0;i<n;i++){
            if (i-k < 0 || i+k > n-1){
                avgs.push_back(-1);
            } else {
                long val = prefix[i+k] - prefix[i-k] + nums [i-k];
                avgs.push_back(val/kSize);
            }
        }
        return avgs;
    }
};