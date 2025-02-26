class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int longest = 0;
        for (int right = 0,left = 0;right<nums.size();right++){
            freq[nums[right]]++;
            while (freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
            longest = max(longest,right-left+1);
        }
        return longest;
    }
};