class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];

            graph[A].push_back({B, value});    // A / B = value
            graph[B].push_back({A, 1.0 / value}); // B / A = 1 / value
        }
        vector<double> results;
        for (auto& query : queries) {
            unordered_map<string, bool> visited;
            results.push_back(dfs(query[0], query[1], visited, graph));
        }
        return results;
    }

    double dfs(string u, string v, unordered_map<string,bool>& visited, unordered_map<string,vector<pair<string, double>>>& graph) {
        if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
            return -1.0;
        }
        if (u == v) {
            return 1.0;
        }
        visited[u] = true;

        for (auto& [neighbor, weight] : graph[u]) {
            if (!visited[neighbor]) {
                double result = dfs(neighbor,v,visited,graph);
                if (result != -1.0) {
                    return result * weight;
                }
            }   
        }
        return -1.0;
    }
};