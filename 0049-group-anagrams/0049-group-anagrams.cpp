class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> map1;
    for (string s : strs){
        string word = s;
        sort(word.begin(),word.end());
        map1[word].push_back(s);
    } 
    vector<vector<string>> ans;
    for (auto m : map1){
        ans.push_back(m.second);
    }
    return ans;
    }
};