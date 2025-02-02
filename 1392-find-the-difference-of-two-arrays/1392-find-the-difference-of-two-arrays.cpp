class Solution {
private:
    vector<int> distictinOne(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> set1 (nums2.begin(),nums2.end());
        unordered_set<int> set2;
        for (auto num : nums1){
            if (!set1.count(num)){
                set2.insert(num);
            }
        }
        return vector<int> (set2.begin(),set2.end());
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {distictinOne(nums1,nums2),distictinOne(nums2,nums1)};
        }
};