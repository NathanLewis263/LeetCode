class Solution {
private:
    void dfs(int node, vector<vector<int>>& graph, set<pair<int,int>>& edges, vector<bool>& visit, int& changes){
        visit[node] = true;
        for (auto& neighbour : graph[node]){
            if (!visit[neighbour]){
                if (!edges.count({neighbour, node})) {
                    changes++;
                }
                dfs(neighbour,graph,edges,visit,changes);
            }
        }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        set<pair<int,int>> edges;

        // Build adjacency list and store directed edges
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);  // Undirected representation
            edges.emplace(u,v); // Mark original direction
        }
        int changes = 0;
        vector<bool> visit(n);
        dfs(0,graph,edges,visit,changes);
        return changes; 
    }
};
