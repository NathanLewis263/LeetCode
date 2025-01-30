class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9]; // nine rows
        unordered_set<char> cols[9]; // nine coloums
        unordered_set<char> box[3][3]; //three boxes in each row and column. row index for box is r/3 
                                       //and for coloum its c/3
        for (int r = 0;r<9;++r){
            for (int c = 0;c<9;++c){
                if (board.at(r).at(c) == '.'){
                    continue;
                
                }  
                char value = board.at(r).at(c);
                if ((rows[r].find(value) != rows[r].end()) || 
                    (cols[c].find(value) != cols[c].end()) || 
                    (box[r/3][c/3].find(value) != box[r/3][c/3].end())) {
                        return false;
                    }
                
                rows[r].insert(value);
                cols[c].insert(value);
                box[r/3][c/3].insert(value); 
            }
        }
        return true;
    }
};