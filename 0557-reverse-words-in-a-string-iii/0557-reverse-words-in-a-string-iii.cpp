class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0;
        for (int i = 0;i<=n;i++){
            if (i == n || s[i] == ' '){
                for (int l = left, r = i - 1; l < r; l++, r--) { 
                    swap(s[l], s[r]);
                }
                left = i + 1; // Move to the next word
            }
        }
        return s;
    };
};