class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> rowsFreq;
        int pairs = 0;
        for (auto value : grid){
            rowsFreq[value]++;
        }

        for (int c = 0;c<grid.size();c++){
            vector<int> col(grid.size());
            for (int r = 0;r<grid.size();r++){
                col.at(r) = grid.at(r).at(c);
            }
            pairs += rowsFreq[col];
        }
        return pairs;
    }
};