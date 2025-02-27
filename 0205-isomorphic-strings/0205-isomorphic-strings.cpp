class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, char> st, ts;  // Maps s -> t and t -> s
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            // Check if s -> t mapping is consistent
            if (st.count(c1) && st[c1] != c2) return false;

            // Check if t -> s mapping is consistent
            if (ts.count(c2) && ts[c2] != c1) return false;

            // Create new mappings
            st[c1] = c2;
            ts[c2] = c1;
        }

        return true;
    }
};