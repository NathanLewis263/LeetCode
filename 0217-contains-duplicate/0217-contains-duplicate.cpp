class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    set<int> p;
    int size = nums.size();
    for (size_t i = 0; i<size;i++){
        p.insert(nums[i]);
    }
    return size>p.size();
    }
};