class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenthesesMap = {{')', '('},{']','['},{'}','{'}};
        stack<char> stack;
        for (char c : s){
            if (parenthesesMap.count(c)){
                if (!stack.empty() && stack.top()==parenthesesMap[c]){
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        
        return stack.empty();
    }
};