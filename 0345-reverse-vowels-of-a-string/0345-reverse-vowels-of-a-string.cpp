class Solution {
public:
    bool isvowel(char& c){
        string vowels = "aeiouAEIOU";
        if (vowels.find(c) != string::npos){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        vector<char> vowel;
        vector<int> loca;
        for (int i = 0; i < s.size();i++){
            if (isvowel(s[i])){
                vowel.push_back(s[i]);
                loca.push_back(i);
            }
        }
        for (int i = vowel.size()-1;i>-1;i--){
            s.replace(loca.at(vowel.size()-1-i),1,1,vowel.at(i));
        }
        return s;
    }
};