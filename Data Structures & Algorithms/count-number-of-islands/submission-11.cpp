class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // In-place BFS: mutate grid '1' -> '0' to mark visited.
        // Time: O(rows * cols) because each cell is processed at most once.
        // Space: O(queue) for the frontier; no separate visited array.
        queue<pair<int,int>> q;          // FIFO frontier of {row, col}
        int rows = grid.size();          // m
        int cols = grid[0].size();       // n (assumes grid is non-empty)
        int result = 0;                  // island count

        // Scan every cell. Each unvisited '1' starts a new island.
        for (int i=0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                // Water cells, or land already sunk by another BFS, are skipped.
                if (grid[i][j] == '0') {
                    continue;
                }

                // New island found: seed BFS and sink the root immediately
                // so it cannot be re-enqueued from a neighbor.
                q.push({i,j});
                grid[i][j] = '0';

                // Flood-fill all land reachable from this seed.
                while (!q.empty()) {
                    auto [row, col] = q.front(); // C++17 structured binding
                    q.pop();

                    // Explore four neighbors independently. Mark each as visited
                    // (sink) at enqueue time to avoid pushing the same cell twice.
                    if (row + 1 < rows && grid[row+1][col] == '1') {
                        grid[row+1][col] = '0';
                        q.push({row+1, col});     // down
                    }
                    if (row - 1 >= 0 && grid[row-1][col] == '1') {
                        grid[row-1][col] = '0';
                        q.push({row-1, col});     // up
                    }
                    if (col - 1 >= 0 && grid[row][col-1] == '1') {
                        grid[row][col-1] = '0';
                        q.push({row, col-1});     // left
                    }
                    if (col + 1 < cols && grid[row][col+1] == '1') {
                        grid[row][col+1] = '0';
                        q.push({row, col+1});     // right
                    }
                }

                // BFS finished; one connected island counted.
                result++;
            }
        }

        return result;
    }
};
