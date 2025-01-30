class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int smallestSize;
        string substring = "";
        if (size1 == size2){
            smallestSize = size1;
        } else if (size1 < size2){
            smallestSize = size1;
            substring = word2.substr(size1,size2-size1);
        } else {
            smallestSize = size2;
            substring = word1.substr(size2,size1-size2);
        }
        string merged = "";
        for (int i = 0; i < smallestSize; i++){
            merged+=word1[i];
            merged+=word2[i];
        }
        merged += substring;
        return merged;
    }
};