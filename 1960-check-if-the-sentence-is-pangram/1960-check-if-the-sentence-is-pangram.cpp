class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> set;
        for (int i = 0;i<sentence.size();i++){
            set.insert(sentence[i]);
        }
        return set.size() == 26;
    }
};