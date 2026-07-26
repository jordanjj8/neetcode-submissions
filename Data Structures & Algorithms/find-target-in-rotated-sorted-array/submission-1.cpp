class Solution {
public:
    int search(vector<int>& nums, int target) {
    /*
        0 1 2 3 4 5 
        3 4 5 6 1 2 
        l     
                  r
            m
              l
        m = l + (r -l)/2 
        m = 2 -> nums[m] = 5
        if nums[m] == target
        then return m 
        if not then: 
        *need to discard one side

        if nums[m] > nums[r]
        then left side is sorted, so pivot is [m , r]
            if nums[m] > target
            then target is in the right
            if nums[m] < target
            then if nums[l] < target 
            then target is in the left
            if nums[l] > target 
            then target is in the right
        else right side is sorted
            if nums[m] > target
            then target is left
            if nums[m] < target 
            then target is on rhe right 


    */
        int l = 0;
        int r = nums.size() -1;
        // keep searching while [l, r] is non empty
        while (l <= r) {
            int m = l + (r -l)/2;
            
            // best case: 
            if (target == nums[m]) {
                return m;
            }

            // in rotated sorted array, one half is always sorted
            // 1. check if left half is sorted [l, mid]
            if (nums[m] > nums[r]) {
                // is target in the sorted portion?
                // if target is, too big or too small of sorted portion
                // then its on right side
                if (target > nums[m] || target < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            // 2. right side is sorted
            } else {
                // is target in the sorted portion?
                // if target is too big or too small of sorted portion
                // then its on the left
                if (target > nums[r] || target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
 
        // Interval became empty without finding target.
        return -1;
    }
};
