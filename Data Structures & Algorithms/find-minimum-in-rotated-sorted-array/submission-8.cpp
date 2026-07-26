class Solution {
public:
    int findMin(vector<int> &nums) {
        /* 0 1 2 3 4 5
        // 3 4 5 6 1 2
        //       l 
        //       h
        //         m
        // m = (l + (h - l))/2
        // m = 0 + (5-0)/2 = floor(2.5) = 2
        // 
        // 2. m = 3 + (5-3)/2 = 4
        // if nums[m] > nums[h]
        // then left side is sorted, then min must be in [m,h]
        //      l = m + 1
        // if nums[m] < nums[l] 
        // then right side is sorted, then min must be in [l, m]
        //      h = m - 1
        // if h =  m -1
        // then return nums[m]
        */
        int l = 0;
        int h = nums.size() -1;
        // shrink until 1 candidate remains 
        while (l < h) {
            int mid = l + (h - l)/2;
            // in rotated sorted array, one half is sorted
            // compare mid against right edge to decide which half is sorted
            if (nums[mid] > nums[h]) {
                // left side is sorted
                // min is in [m, h]
                l = mid + 1; // nums[mid] cannot be min
            } else {
                // right side [mid, h] is sorted
                // min is in [l, mid]
                h = mid; // keep mid, it might be min
            }
        }
        return nums[l]; // or num[h]
    }
};
