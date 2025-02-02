class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefixSum(gain.size());
        prefixSum.at(0) = gain.at(0);        
        int maxHeight = max(0,prefixSum.at(0));
        for (int i = 1;i<gain.size();++i){
            prefixSum.at(i) = prefixSum.at(i-1)+gain.at(i);
            maxHeight = max(maxHeight,prefixSum.at(i));
        }
        return maxHeight;
    }
};