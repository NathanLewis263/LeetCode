class Codec {
public:
    string encode(vector<string>& strs) {
        stringstream ss; // use string stream
        for (auto& str : strs){
            ss << "#" << str.size() << "#" << str; //add hashtags beore and after the size of the string
        }

        return ss.str();

    }

    vector<string> decode(string s) {
        int i = 0;
        string word;
        vector<string> ans;
        while (i < s.size())
            if (s[i] == '#'){
                i++; // move past the first hashtag
                int j = i;

                while (s[j] != '#'){
                    j++; // find and store location of second hashtag in j
                }
                
                int len = stoi(s.substr(i,j-i)); // convert substring that contains size to int
                i = j + 1;
                word = s.substr(j+1,len); // move past the second hashtag and use len to get the word
                ans.push_back(word); // add word to vector
                i += len;
            }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));