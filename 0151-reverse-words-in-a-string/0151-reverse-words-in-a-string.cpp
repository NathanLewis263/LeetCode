class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); //string to stringstream
        vector<string> splitString; 
        string word;
        while (ss >> word){ //use string stream to split words at space 
            splitString.push_back(word);
        }
        word = "";
        for (auto it = splitString.end()-1;it!=splitString.begin()-1;it--){
            word+=*it;
            if (it!=splitString.begin()){
                word+=" ";
            }
        }
        return word;
    }
};
//getline(inputStream(cin or stringstream),string s,char delim) can be used if delim is anything other than space