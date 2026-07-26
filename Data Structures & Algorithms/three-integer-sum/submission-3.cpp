class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* sort the array first, which lets me
        fix one number while iterating through nums
        and use two pointers to find a pair that sums to 
        negative of that fixed number. 
        - since the array is sorted, i can move l right
        when the sum is too small and r left when sum is too large
        - since the array is sorted, the duplicate values are adjacent
        so i can skip repeated values at each pointer (i, l, r) to avoid outputting
        the same triplet more than once
        */
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; 
        
        
        // i holds the smallest number compared to l and r
        for (int i = 0; i < nums.size(); i++) {
            // skip duplicate of first pointer
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() -1;
            // do two pointer until left crosses right
            while (l < r ) {
                // check if the sum of the values that l & r point
                // is equal to the -nums[i]
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    //match found 
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // to avoid duplicates 
                    // [-1, 0, 0, 1, 1]
                    //  i   l        r 
                    //         l  r
                    //            l 
                    while (l < r && nums[l] == nums[l-1]) {
                        // advance l when we see duplicate
                        l++;
                    }
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                // [-1 0 1 1 1 2]
                //  i  l     r
                // sum = 1, want: 0 
                } else if (sum > 0) {
                    r--;
                // [-1 -1 0 1 1 2]
                //  i     l   r
                // sum = -1, want: 0 
                } else if (sum < 0) {
                    l++;
                }
            }
        }

        return res;

    }
};
