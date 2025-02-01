class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> triplets;
        for (int i = 0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // skip if next element is the same number
            }
            int left = i+1;
            int right = nums.size()-1;
            while (left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if (sum == 0){
                    triplets.push_back({nums[left],nums[right],nums[i]});
                    while (left < right && nums[left]==nums[left+1]){
                        left++; //skip if next element to the left is the same number
                    }
                    while (left < right && nums[right]==nums[right-1]){
                        right--; //skip if next element to the rifht is the same number
                    }
                    left++;
                    right--;
                } else if (sum < 0){
                    left++;
                } else {
                    right--;
                }
            }
        }
        return triplets;
    }
};