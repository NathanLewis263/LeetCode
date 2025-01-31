class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> splitString;
        string word;
        while (ss >> word){
            splitString.push_back(word);
        }
        word = "";
        for (auto it = splitString.end()-1;it!=splitString.begin()-1;it--){
            for (int i = 0;i<40;i++){}
            word+=*it;
            if (it!=splitString.begin()){
                word+=" ";
            }
        }
        return word;
    }
};