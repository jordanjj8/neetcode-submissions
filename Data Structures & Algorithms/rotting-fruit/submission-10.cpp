class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Time: O(rows * cols) because each cell is enqueued at most once.
        // Space: O(rows * cols) for the queue in the worst case plus the seen grid.
        int fresh = 0;   // number of fresh oranges that still need to rot
        int rotten = 0;  // number of initially rotten oranges (BFS sources)
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q; // each entry is {row, col} of a rotten orange

        // Pass 1: scan the entire grid once.
        // Enqueue all initially rotten oranges and count both rotten and fresh.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                    seen[row][col] = true; // mark source as visited
                    rotten++;
                }
                if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        // Edge case: no fresh oranges means nothing needs to rot.
        if (fresh == 0) {
            return 0;
        }

        // Edge case: fresh oranges exist but no rotten source to spread from.
        if (rotten == 0) {
            return -1;
        }

        int minutes = -1;

        // Pass 2: multi-source level-order BFS.
        // All initially rotten oranges are in the queue. Each outer while iteration
        // represents one minute; we process every orange that rotted in the
        // previous minute before advancing time.
        while (!q.empty()) {
            int levelSize = q.size(); // snapshot: oranges rotting at current minute
            minutes++;                // one minute elapses per BFS level

            for (int level = 0; level < levelSize; level++) {
                auto [i, j] = q.front();
                q.pop();

                // Try to rot each of the 4 adjacent cells.
                // A neighbor must be in bounds, not yet seen, and still fresh.

                // down
                if (i + 1 < rows && seen[i+1][j] == false && grid[i+1][j] == 1) {
                    q.push({i+1, j});
                    seen[i+1][j] = true;
                    fresh--;
                }
                // right
                if (j + 1 < cols && seen[i][j+1] == false && grid[i][j+1] == 1) {
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

        // If any fresh orange is still left, it was unreachable from any rotten source.
        if (fresh != 0) {
            return -1;
        }

        // minutes is the last level processed; that equals elapsed minutes.
        return minutes;
    }
};
