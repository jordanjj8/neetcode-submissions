class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // - iterate through each cell 
        // if cell == '1'
        // then
        // add cell (coordinates to the queue)
        // mark it as seen 
        // -  do bfs (while queue is not empty)
        // explore all directions and add to queue 
        // if 1. we have not seen it
        //    2. if not out of bounds
        // - increment number of islands
        // return numIslands

        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int numIslands = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col= 0; col < cols; ++col) {
                // check if cell is '1'
                if (grid[row][col] == '1') {
                    // mark as seen and add to queue
                    grid[row][col] = '0';
                    q.push({row,col});

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        // explore all four directions
                        if (r + 1 < rows && grid[r + 1][c] == '1') {
                            // bottom
                            q.push({r+1, c});
                            grid[r+1][c] = '0';
                        } 
                        if (c + 1 < cols && grid[r][c+1] == '1') {
                            // right
                            q.push({r, c+1});
                            grid[r][c+1] = '0';
                        }
                        if (r - 1 >= 0 && grid[r -1][c] == '1') {
                            // top
                            q.push({r-1, c});
                            grid[r-1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c-1] == '1') {
                            // left
                            q.push({r, c-1});
                            grid[r][c-1] = '0';
                        }
                    }
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }
};
