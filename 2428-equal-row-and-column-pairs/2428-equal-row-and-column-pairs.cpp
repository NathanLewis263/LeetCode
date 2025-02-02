class Solution {
private:
    string tostring(vector<int> value){
        string s = "";
        for (int val : value){
            s+=to_string(val)+" ";
        }
        return s;
    };
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> rowsFreq;
        int pairs = 0;
        for (auto value : grid){
            string s = tostring(value);
            rowsFreq[s]++;
        }

        for (int c = 0;c<grid.size();c++){
            vector<int> col(grid.size());
            for (int r = 0;r<grid.size();r++){
                col.at(r) = grid.at(r).at(c);
            }
            pairs += rowsFreq[tostring(col)];
        }
        return pairs;
    }
};