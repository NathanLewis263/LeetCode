class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiouAEIOU";
        int numberOfVowels = 0;
        for (int i = 0;i<k;i++){
            numberOfVowels += isVowel(s[i],vowels);
        }
        int maxNum = numberOfVowels;
        int left = 0;
        for (int right = k;right<s.size();right++,left++){
            numberOfVowels += isVowel(s[right],vowels);
            numberOfVowels -= isVowel(s[right-k],vowels);
            maxNum = max(numberOfVowels,maxNum);
        }

        return maxNum;
    }


    bool isVowel(char& c, string& vowels){
        if (vowels.find(c) != string::npos){
            return true;
        } else {
            return false;
        }
    }
};