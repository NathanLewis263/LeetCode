class Solution {
public:
    string makeGood(string s) {
        string stack = "";
        for (char& c: s){
            if (!stack.empty() && (tolower(stack.back()) == tolower(c) && stack.back() != c)){
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }
        return stack;
    }
};