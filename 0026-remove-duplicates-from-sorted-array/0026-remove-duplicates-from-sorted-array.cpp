class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> elements(nums.begin(),nums.end());
        int k = elements.size();
        auto it = elements.begin();
        for (int i=0;i<k;i++,it++){
            nums.at(i) = *it;
        }
        return k;
    }
};