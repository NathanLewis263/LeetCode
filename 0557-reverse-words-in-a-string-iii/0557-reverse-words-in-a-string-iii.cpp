class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        while (right <= n){
            if (right == n || s[right] == ' '){
                int l = left, r = right-1;
                while (l<r){
                    swap(s[l++], s[r--]);
                }
                left = right + 1; 
            }
            right++;
        }
        return s;
    };
};