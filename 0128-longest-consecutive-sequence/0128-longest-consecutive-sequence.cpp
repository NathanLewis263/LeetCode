class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set1(nums.begin(),nums.end());
        int longest = 0;
        for (auto i : set1){
            auto num = i;
            int count = 0;
            if (set1.find(num-1)==set1.end()){
                count += 1;
                while (set1.find(num+1)!=set1.end()){
                    count += 1;
                    num++;
                }
            } 
            longest = max(longest,count);
        }
        return longest;
    }
};