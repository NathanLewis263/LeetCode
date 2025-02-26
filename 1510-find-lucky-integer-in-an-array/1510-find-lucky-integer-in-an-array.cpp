class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map;
        int maxFreak = -1;
        for (auto& num : arr){
            map[num]++;
        }
        for (auto& pair : map){
            if (pair.second == pair.first){
                maxFreak = max(maxFreak,pair.first);
            }
        }
        return maxFreak;
    }
};