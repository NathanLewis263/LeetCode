class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()){
            return false;
        }
        unordered_map<char,int> map1,map2;
        unordered_multiset<char> word1Set, word2Set;
        unordered_multiset<int>  freq1Set, freq2Set;
        for (int i = 0;i<word1.size();i++){
            map1[word1[i]]++;
            map2[word2[i]]++;
        }
        for (auto pair : map1) {
            word1Set.insert(pair.first);
            freq1Set.insert(pair.second);
        }
        for (auto pair : map2) {
            word2Set.insert(pair.first);
            freq2Set.insert(pair.second);
        }

        if (word1Set != word2Set || freq1Set != freq2Set ){
            return false;
        } else {
            return true;
        }
     
    }
};