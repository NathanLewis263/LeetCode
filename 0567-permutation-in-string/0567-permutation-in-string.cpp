class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false; //s1 can't be in s2 if it's longer

        unordered_map<char, int> s1_freq, s2_freq;

        // Step 1: Build frequency map for s1
        for (char c : s1) {
            s1_freq[c]++;
        }

        // Step 2: Process first window in s2
        for (int i = 0; i < n; i++) {
            s2_freq[s2[i]]++;
        }
        if (s2_freq == s1_freq){
                return true;
        } 
        for (int i = n;i<m;i++){
            s2_freq[s2[i - n]]--;
            s2_freq[s2[i]]++;   
            if (s2_freq[s2[i-n]]==0){
                s2_freq.erase(s2[i-n]);
            }    
            if (s2_freq == s1_freq){
                return true;
            }
        }
        return false;
    }
};