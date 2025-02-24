class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0){ // return nums if k is 0
            return nums;
        }

        int n = nums.size();
        
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1;i<n;i++){
             prefix[i] = prefix[i-1] + nums[i];
         }
        
        vector<int> avgs(n,-1);
        int kSize = 2 * k + 1;

        for (int i = k;i<n-k;i++){
                long val = prefix[i+k] - prefix[i-k] + nums [i-k];
                avgs[i]=(val/kSize);
        }
        return avgs;
    }
};