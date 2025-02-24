class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int maxC = 0;
        for (int i = 0,left = 0;i<s.length();i++){
            cost += abs(s[i]-t[i]);
            while (cost>maxCost){
                cost -= abs(s[left]-t[left]);
                left++;
            }
            maxC = max(maxC,i-left+1);
        }
        return maxC;
    }
};