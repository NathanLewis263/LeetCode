class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size());
        seen.at(0) = true;
        stack<int> st;
        st.push(0);
        while (!st.empty()) { 
            int node = st.top();
            st.pop(); 
            for (int i : rooms.at(node)) 
                if (!seen[i]) { 
                    seen[i] = true; 
                    st.push(i); 
                }
        }
        for (bool b : seen){
            if (!b) {
                return b;
            }
        }
        return true;
    }
};