class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0;
        int longest = 0;
        for (int right = 0;right<s.size();right++){
            freq[s[right]]++;
            if (freq[s[right]]>1){
                while (freq[s[right]]>1){
                    freq[s[left]]--;
                    left++;
                }
            }
            longest = max(longest,right-left+1);
        }
        return longest;
    }
};