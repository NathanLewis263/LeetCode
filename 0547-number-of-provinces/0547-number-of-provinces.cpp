class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { 
                provinces++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
        
            while (!q.empty()) {
                    int city = q.front();
                    q.pop();
                    
                    // Traverse all cities
                    for (int neighbor = 0; neighbor < n; neighbor++) {
                        if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                            q.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
            }
        }
        return provinces;
    }
};