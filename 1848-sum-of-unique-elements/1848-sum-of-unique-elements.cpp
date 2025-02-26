class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> freak;
        for (auto& num : nums){
            freak[num]++;
        }
        int sum = 0;
        for (auto& pair : freak){
            if (pair.second == 1){
                sum+=pair.first;
            }
        }
        return sum;
    }
};