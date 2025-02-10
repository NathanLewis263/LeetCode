#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // Down, Up, Right, Left

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // Mark visited
        int steps = 0;

        while (!q.empty()) {
            int q_size = q.size();
            steps++;

            for (int i = 0; i < q_size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];

                    // Check if the next position is valid
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && maze[nx][ny] == '.') {
                        // If it's an exit and not the entrance, return the steps
                        if (nx == 0 || ny == 0 || nx == rows - 1 || ny == cols - 1) {
                            return steps;
                        }

                        q.push({nx, ny});
                        maze[nx][ny] = '+'; // Mark as visited
                    }
                }
            }
        }

        return -1; // No exit found
    }
};
