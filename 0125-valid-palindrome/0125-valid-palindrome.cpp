class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()){return true;}

        string modifyString = "";
        for (int i = 0;i<s.size();i++){
            if (isalnum(s[i])){
                modifyString += tolower(s[i]);
            } 
        }
        int left = 0;
        int right = modifyString.size()-1;
        while (left<right){
            if (modifyString[left]!=modifyString[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};