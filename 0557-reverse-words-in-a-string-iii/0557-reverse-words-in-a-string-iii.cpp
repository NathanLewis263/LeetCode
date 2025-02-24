class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        for (int i = 0;i<=n;i++){
            if (i == n || s[i] == ' '){
                right = i - 1;
                while (left < right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                left = i+1;
            }
        }
        return s;
    };
};