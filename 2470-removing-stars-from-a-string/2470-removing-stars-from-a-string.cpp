class Solution {
public:
    string removeStars(string s) {
        string noStars = "";
        for (char& ch : s){
            if (ch == '*' && !noStars.empty()){
                noStars.pop_back();
            } else {
                noStars.push_back(ch);
            }
        }
        return noStars;
    }
};