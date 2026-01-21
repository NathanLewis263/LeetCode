class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        boolean[] visited = new boolean[n];
        for (int[] edge : edges) {
            int a = edge[0], b = edge[1];
            graph.putIfAbsent(a, new ArrayList<>());
            graph.putIfAbsent(b, new ArrayList<>());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        return dfs(graph, visited, source, destination);
    }

    private boolean dfs(Map<Integer, List<Integer>> graph, boolean[] visited, int curr, int destination){
        if (curr == destination){
            return true;
        }

        visited[curr] = true;
        for (int nextNode : graph.get(curr)) {
            if (!visited[nextNode]) {  // Only call dfs if not seen
                if (dfs(graph, visited, nextNode, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
}