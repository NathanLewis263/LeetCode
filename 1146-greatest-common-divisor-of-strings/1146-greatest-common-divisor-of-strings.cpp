class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1+str2 != str2+str1){
            return "";
            }
        int size = str1.size();
        int size2 = str2.size();
        int greaterSize = gcd(size,size2);
        return str1.substr(0,greaterSize);
    }
};