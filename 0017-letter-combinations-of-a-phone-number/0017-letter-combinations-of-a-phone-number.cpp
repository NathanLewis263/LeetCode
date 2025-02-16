class Solution {
public:
    vector<string> phoneMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // Mapping for digits

    void backtrack(string& digits, int index, string current, vector<string>& result) {
        if (index == digits.size()) { // Base case: if all digits are processed
            result.push_back(current);
            return;
        }
        
        string letters = phoneMap[digits[index] - '0']; // Get letters for the current digit
        
        for (char letter : letters) { // Iterate over possible letters
            backtrack(digits, index + 1, current + letter, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        backtrack(digits, 0, "", result);
        return result;
    }
};