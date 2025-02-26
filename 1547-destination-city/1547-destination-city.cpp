class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> map;
        for (auto& path : paths){
            map[path[0]] = path[1];
        }

        string start = paths[0][0];
        while (map.find(start) != map.end()){
            start = map[start];
        }
        return start;
    };
};