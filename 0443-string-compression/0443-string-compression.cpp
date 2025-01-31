class Solution {
public:
    int compress(vector<char>& chars) {
      string s = "";
      for (int i = 0;i<chars.size();i++){
        s+=chars[i];
        char currentChar = chars[i];
        int count = 1;
        while ((i+1 != chars.size() && currentChar == chars[i+1])){
            count++;
            i++;
        }
        if (count>1){
            s+=to_string(count);
        }
      }
      chars.resize(s.size());
      for (int i = 0;i<s.size();i++){
        chars[i] = s[i];
      }
      return s.size();
    }
};