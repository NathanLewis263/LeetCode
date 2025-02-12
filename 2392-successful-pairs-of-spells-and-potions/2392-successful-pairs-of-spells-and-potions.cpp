class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> answer;
        for (auto& spell : spells) {
            long long min = ceil((double)success/spell);
            if (min > potions[m-1]){
                answer.push_back(0);
                continue;
            } else {
                answer.push_back(m-(lower_bound(potions.begin(), potions.end(), min)-potions.begin()));
            }
        }
        return answer;
    }
};