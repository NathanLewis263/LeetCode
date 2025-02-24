class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto j = word.find(ch);
        if (j != string::npos){
            for(int i = 0;i<j;i++){
                swap(word[i],word[j]);
                j--;
            }
        }
        return word;
    }
};