class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};

        q.emplace(entrance[0], entrance[1]);
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            int q_size = q.size();
            count++;
            
            for (int i = 0; i < q_size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& dir : direction) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];    
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && maze[nx][ny] == '.'){
                        if (nx == 0 || ny == 0 || nx == rows - 1 || ny == cols - 1) {
                            return count;
                        }
                        q.emplace(nx,ny);
                        maze[nx][ny] = '+';
                    }
                }
            }
        }
        return -1;    
    }
};