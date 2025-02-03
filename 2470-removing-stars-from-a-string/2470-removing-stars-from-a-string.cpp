class Solution {
public:
    string removeStars(string s) {
        stack<char> word;
        for (int i = 0;i<s.size();i++){
            if (s[i] == '*' && !word.empty()){
                word.pop();
            } else {
                word.push(s[i]);
            }
        }
        string noStars = "";
        int size = word.size();
        for (int i = 0;i<size;i++){
            noStars+=word.top();
            word.pop();
        }
        reverse(noStars.begin(),noStars.end());
        return noStars;
    }
};