class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> elements(nums.begin(),nums.end());
        int k = elements.size();
        auto it = elements.begin();
        for (int i=0;i<nums.size();i++,it++){
            if (i < k){
                nums.at(i) = *it;
            } else {
                nums.at(i) = 0;
            }
        }
        return k;
    }
};