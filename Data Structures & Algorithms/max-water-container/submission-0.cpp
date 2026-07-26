class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 1 7 2 5 4 7 3 6
        // 0 1 2 3 4 5 6 7
        //   l
        //               r
        // res= (r-l)* min(heights[l], heights[r])
        // start l at 0, r at end 
        // start at max window, then narrow
        // we shrink by moving the shorter wall
        
        int l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;
        while (l < r) {
            int area = (r - l)*min(heights[l], heights[r]);
            maxArea = max(maxArea, area);
            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }
        return maxArea;
    }
};
