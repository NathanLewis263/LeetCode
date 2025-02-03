class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0;i<s.size();i++){
            if (s[i] == ']'){
                string decode = "";
                while (st.top() != '['){
                    decode += st.top();
                    st.pop();
                }
                st.pop();
                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.top())) {
                    k = k + (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }
                while (k != 0) {
                    for (int j = decode.size() - 1; j >= 0; j--) {
                        st.push(decode[j]);
                    }
                    k--;
                }
            }
            else {
                st.push(s[i]);
            }
        }
        string result;
        while (!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};