class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int num = 0;
        for (int i = 0;i<s.size();i++){
           int val = map[s[i]]; 
           if (s[i] == 'I' && i != s.size()-1 && (s[i+1] == 'V' || s[i+1] == 'X')){
                val = map[s[i+1]]-map[s[i]];
                i++;
           } else if (s[i] == 'X' && i != s.size()-1 && (s[i+1] == 'L' || s[i+1] == 'C')) {
                val = map[s[i+1]]-map[s[i]];
                i++;
           } else if (s[i] == 'C' && i != s.size()-1 && (s[i+1] == 'D' || s[i+1] == 'M')) {
                val = map[s[i+1]]-map[s[i]];
                i++;
           } 
           num += val;
        }
        return num;
    }
};