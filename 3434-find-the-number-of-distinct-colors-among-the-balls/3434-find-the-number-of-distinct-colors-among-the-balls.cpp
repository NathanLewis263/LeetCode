class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> colourMap,ballMap;
        vector<int> result;
        for (auto& query : queries){
            if (ballMap.count(query[0]) != 0){
                int prev = ballMap[query[0]];
                colourMap[prev]--;
                if (colourMap[prev] == 0) colourMap.erase(prev);
            }
            ballMap[query[0]] = query[1];
            colourMap[query[1]]++;
            result.push_back(colourMap.size());
        }
        return result;
    }
};