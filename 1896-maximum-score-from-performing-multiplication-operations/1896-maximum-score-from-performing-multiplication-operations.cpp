class Solution {
public:
    int m;
    int n;
    vector<vector<int>> memo;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
            m = multipliers.size();
            n = nums.size();
            memo = vector<vector<int>>(m,vector<int>(m,0));
            return maxScore(0,0,nums,multipliers);
    }
    
    int maxScore(int i,int left,vector<int>& nums, vector<int>& multipliers){
        if (i==m){
            return 0;
        }
        int mult = multipliers[i];
        int right = n - 1 - (i - left);
            
        if (memo[i][left] == 0) {
            memo[i][left] = max(mult * nums[left] + maxScore(i + 1, left + 1,nums,multipliers), 
                            mult * nums[right] + maxScore(i + 1, left,nums,multipliers));
        }
        return memo[i][left];
        
    }
};