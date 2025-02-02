class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix = gain.at(0);
        int maxHeight = max(0,prefix);
        for (int i = 1;i<gain.size();++i){
            prefix += gain.at(i);
            maxHeight = max(maxHeight,prefix);
        }
        return maxHeight;
    }
};