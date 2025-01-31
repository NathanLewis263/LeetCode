class Solution {
public:
    int compress(vector<char>& chars) {
      string s = "";
      
      for (int i = 0;i<chars.size();i++){
        s+=chars[i]; //append char to string
        char currentChar = chars[i];
        int count = 1;
        //count how many consecutive repeating chars exist;
        while ((i+1 != chars.size() && currentChar == chars[i+1])){
            count++;
            i++;
        }
        //append to string only if count is more than 1;
        if (count>1){
            s+=to_string(count);
        }
      }
      
      //modify input array;
      chars.resize(s.size());
      for (int i = 0;i<s.size();i++){
        chars[i] = s[i];
      }

      //return size;
      return chars.size();
    }
};