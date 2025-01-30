class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> p;
    int size = nums.size();
    for (size_t i = 0; i<size;i++){
        p.insert(nums[i]);
        if (i+1>p.size()){
            return true;
        }
    }
    return false;
    }
};