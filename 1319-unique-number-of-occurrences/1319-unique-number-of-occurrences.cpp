class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map1;
        unordered_set<int> set1;
        for (int num : arr){
            map1[num]++;
        }
        
        for (auto pair : map1){
            set1.insert(pair.second);
        }
        return map1.size() - set1.size() == 0;
    }
};