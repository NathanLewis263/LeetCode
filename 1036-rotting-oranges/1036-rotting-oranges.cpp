class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q; // store rotten orange position 
        vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}}; // directions;
        int fresh = 0;

        for (int i = 0;i<rows;i++) { // count fresh oranges and store rotten oranges position
            for (int j = 0;j<cols;j++){
                if (grid[i][j] == 2){
                    q.emplace(i,j);
                } else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if (fresh == 0){
            return 0;
        }

        int min = 0;

        while (!q.empty()){ // bfs
            int size = q.size();
            bool rotted = false;
            for (int i = 0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();
                for (auto& dir : direction){
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted){ // only increase if atleast one orange gets rotten after checking all 4 direction
                min++;
            }
            if (fresh == 0){ // return minutes as soon as all oranges are rotten
                return min;
            }
        }

        return -1;
    }
};