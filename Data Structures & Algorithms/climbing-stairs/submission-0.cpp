class Solution {
public:
    int climbStairs(int n) {
        // handle base cases: n = 2, 1, or 0
        if (n <= 2) {
            return n;
        }
        // vector for storing ways to climb stairs for each n
        vector<int> ways(n+1, 0);
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i <= n; ++i) {
            ways[i] = ways[i - 1] + ways[i-2];
        }

        return ways[n];
    }
};
