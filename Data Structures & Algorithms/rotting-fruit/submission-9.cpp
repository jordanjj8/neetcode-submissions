class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /* Plan
        init 
        seen bool grid
        minMinutes

        1. iterate through every cell in grid
        a. if 

        */
        int fresh = 0;
        int rotten = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> seen(rows, vector<bool>(cols,false));
        queue<pair<int, int>> q;

        // iterate through every cell in grid to find rotten
        for (int row=0; row < rows; row++) {
            for (int col=0; col < cols; col++) {
                // check if grid value == 2
                if (grid[row][col] == 2) {
                    q.push({row, col});
                    seen[row][col] = true;
                    rotten++;
                }
                if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }
        // if no fresh found, always return 0
        if (fresh == 0) {
            return 0;
        }
        int minutes = -1;
        // if no rotten fruits found, then its impossible
        if (rotten == 0) {
            return minutes;
        }
        // start BFS at all the rottens
        while (!q.empty()) {
            int levelSize = q.size();
            minutes++;

            for (int level=0; level < levelSize; level++) {
                auto [i, j] = q.front();
                q.pop();

                // explore all 4 directions of rotten
                // down
                if (i + 1 < rows && seen[i+1][j] == false && grid[i+1][j] == 1) {
                    q.push({i+1, j});
                    seen[i+1][j] = true;
                    fresh--;
                }
                // right
                if (j + 1 < cols && seen[i][j+1] == false &&grid[i][j+1] == 1) {
                    q.push({i, j+1});
                    seen[i][j+1] = true;
                    fresh--;
                }
                // up
                if (i - 1 >= 0 && seen[i-1][j] == false && grid[i-1][j] == 1) {
                    q.push({i-1, j});
                    seen[i-1][j] = true;
                    fresh--;
                }
                // left
                if (j - 1 >= 0 && seen[i][j-1] == false && grid[i][j-1] == 1) {
                    q.push({i, j-1});
                    seen[i][j-1] = true;
                    fresh--;
                }
            }
        }
        if (fresh != 0) {
            return -1;
        }
        return minutes;
    }
};
