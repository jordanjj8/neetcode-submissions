class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // bfs, stop exploring when we hit 0 
        // keep a visited 2d binary grid to keep track of cell seen
        // iterate through the grid and search the cell if not visited
        // use a queue for holding the cells to explore 
        // time O(m*n)
        // space O(m*n) unless you modify in place
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        // visited set that holds row,column
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // iterate per row
        for (int i=0; i < rows; i++) {
            // iterate by column
            for (int j=0; j < cols; j++) {
                // continue to the next cell if cell is visited
                if (visited[i][j] == true) {
                    continue;
                }
                // continue if grid value is 0
                // mark as visited
                if (grid[i][j] == '0') {
                    visited[i][j] = true;
                    continue;
                }
                // grid value is 1
                q.push({i,j});
                visited[i][j] = true;
                // BFS
                while (!q.empty()) {
                    // look left, right, up, down
                    auto [row, col] = q.front();
                    q.pop();
                    // look down
                    if (row + 1 < rows && visited[row+1][col] == false && grid[row+1][col] == '1') {
                        visited[row+1][col] = true;
                        q.push({row+1, col});
                    // look top
                    } 
                    if (row - 1 >= 0 && visited[row-1][col] == false && grid[row-1][col] == '1') {
                        visited[row-1][col] = true;
                        q.push({row-1, col});
                    // look left 
                    } 
                    if (col - 1 >= 0 && visited[row][col-1] == false && grid[row][col-1] == '1') {
                        visited[row][col-1] = true;
                        q.push({row, col-1});
                    // look right
                    }
                    if (col + 1 < cols && visited[row][col+1] == false && grid[row][col+1] == '1') {
                        visited[row][col+1] = true;
                        q.push({row, col+1});
                    }
                }
                result++;
            }
        }
        return result;
    }
};
