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
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // iterate per row
        for (int i=0; i < rows; i++) {
            // iterate by column
            for (int j=0; j < cols; j++) {
                // continue if grid value is 0
                if (grid[i][j] == '0') {
                    continue;
                }
                // grid value is 1
                q.push({i,j});
                grid[i][j] = '0';
                // BFS
                while (!q.empty()) {
                    // look left, right, up, down
                    auto [row, col] = q.front();
                    q.pop();
                    // look down
                    if (row + 1 < rows && grid[row+1][col] == '1') {
                        grid[row+1][col] = '0';
                        q.push({row+1, col});
                    // look top
                    } 
                    if (row - 1 >= 0 && grid[row-1][col] == '1') {
                        grid[row-1][col] = '0';
                        q.push({row-1, col});
                    // look left 
                    } 
                    if (col - 1 >= 0 && grid[row][col-1] == '1') {
                        grid[row][col-1] = '0';
                        q.push({row, col-1});
                    // look right
                    }
                    if (col + 1 < cols && grid[row][col+1] == '1') {
                        grid[row][col+1] = '0';
                        q.push({row, col+1});
                    }
                }
                result++;
            }
        }
        return result;
    }
};
