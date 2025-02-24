class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto j = word.find(ch);
        if (j != string::npos){
            int i = 0;
            while (i<j){
                swap(word[i],word[j]);
                i++;
                j--;
            }
        }
        return word;
    }
};