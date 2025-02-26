class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map;
        int maxFreak = -1;
        for (auto& num : arr){
            map[num]++;
        }
        for (auto& [first,second] : map){
            if (second == first){
                maxFreak = max(maxFreak,first);
            }
        }
        return maxFreak;
    }
};