class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()){
            return true;
        }
        int tStringPointer = 0;
        int sStringPointer = 0;
        while (tStringPointer<t.size()){
            if (s[sStringPointer]==t[tStringPointer]){
                sStringPointer++;
            }
            
            if (sStringPointer == s.size()){
                return true;
            }
            tStringPointer++;
        }
        return false;
    }
};