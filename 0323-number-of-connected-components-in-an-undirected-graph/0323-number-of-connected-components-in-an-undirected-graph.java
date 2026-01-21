class Solution {
    
    private void dfs(List<List<Integer>> adjList, int[] visited, int startNode) {
        visited[startNode] = 1;
         
        // Use a for-each loop for cleaner syntax
        for (int neighbor : adjList.get(startNode)) {
            if (visited[neighbor] == 0) {
                dfs(adjList, visited, neighbor);
            }
        }
    }
    
    public int countComponents(int n, int[][] edges) {
        int components = 0;
        int[] visited = new int[n];
        
        // 1. Initialize the adjacency list
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        
        // 2. Build the graph (Undirected)
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        
        // 3. Traverse the graph
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                dfs(adjList, visited, i);
            }
        }
        
        return components;
    }
}