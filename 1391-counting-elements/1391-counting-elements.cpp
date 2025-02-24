class Solution {
public:
    int countElements(vector<int>& arr) {
        int count = 0; 
        unordered_map<int,int> map;
        for (int num : arr){
            map[num]++;
        }
        for (auto pair : map){
            if (map.find(pair.first+1) != map.end()){
                count += pair.second;
            }
        }
        return count;
    }
};