class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (string s : tokens){
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                int last = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();
                if (s == "+"){
                    numbers.push(first+last);
                } else if (s == "-"){
                    numbers.push(first-last);
                } else if (s == "*") {
                    numbers.push(first*last);
                } else {
                    numbers.push(first/last);
                }
            } else {
                numbers.push(stoi(s));
            }
        }
        return numbers.top();
    }
};