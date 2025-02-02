class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()){
            return false;
        }
        unordered_set<char> set1,set2; 
        unordered_map<char,int> map1,map2; 
        for (int i = 0;i<word1.size();i++){
            set1.insert(word1[i]);
            set2.insert(word2[i]);
            map1[word1[i]]++;
            map2[word2[i]]++;
        }
        if (set1!=set2){
            return false;
        } else {
            unordered_multiset<int> set1,set2;
            for (auto& pair : map1){
                set1.insert(pair.second);
                set2.insert(map2[pair.first]);
            }
            return set1==set2;
        } 
    }
};