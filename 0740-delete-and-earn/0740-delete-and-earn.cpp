class Solution {
public:
    unordered_map<int,int> vals; 
    unordered_map<int,int> dp;
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for (int num : nums) {
            vals[num] += num;
            maxNum = max(maxNum, num);
        } 
        return maxPoints(maxNum);
    }
    
    int maxPoints(int num){
        //baseCase
        if (num == 0){
            return 0;
        }
        
        if (num == 1){
            return vals.count(1) ? vals[num] : 0;
        }
        
        if (dp.count(num)){
            return dp.at(num);
        }
        
        int gain = vals.count(num) ? vals[num] : 0;
        dp[num] = max(maxPoints(num-1),maxPoints(num-2)+gain);
        return dp[num];
    }
};