class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for (auto& cha : s){
            freq[cha]++;
        }
        vector<pair<int,char>> maplist;
        for (auto& [m,n] : freq){
            maplist.emplace_back(n,m);
        }
        sort(maplist.begin(),maplist.end(),greater<>());
        string result;
        for (auto& [count, char_] : maplist) {
            result.append(count, char_);
        }

        return result;
    }
};