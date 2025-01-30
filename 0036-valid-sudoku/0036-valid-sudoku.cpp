class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> box[9];
        for (int r = 0;r<9;++r){
            for (int c = 0;c<9;++c){
                if (board.at(r).at(c) == '.'){
                    continue;
                
                }  
                char value = board.at(r).at(c);
                int boxIndex = (r / 3) * 3 + (c / 3);
                if ((rows[r].find(value) != rows[r].end()) || 
                    (cols[c].find(value) != cols[c].end()) || 
                    (box[boxIndex].find(value) != box[boxIndex].end())) {
                        return false;
                    }
                
                rows[r].insert(value);
                cols[c].insert(value);
                box[boxIndex].insert(value); 
            }
        }
        return true;
    }
};