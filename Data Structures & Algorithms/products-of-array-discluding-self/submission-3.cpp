class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // results[i] = (product of all elements before i) * (product of all elements after i)
        int n = nums.size();
        // create a vector of suffixes
        // create a vecotr of prefixes 
        // vector of product of array (except self):
        // multiply the suffix and prefix at i 
        vector<int> suffixes(n, 1);
        vector<int> prefixes(n, 1);
        vector<int> result(n, 1);

        // find prefixes
        // start from far left, at index 1 since index 0 has no prefix
        for (int i=1; i < n; i++) {
            // prefix: 1  2  4 6 
            // for 2 (i = 1)
            // prefixes[1] = nums[0] *prefixes[0] = 1 * 1 = 1
            // for 4 (i=2)
            // prefixes[2] = nums[1] *prefixes[1] = 2*1 = 2
            prefixes[i] = nums[i - 1] * prefixes[i -1];
        }
        // find the suffixes
        // start from far right, at index n-2, since n-1 index has no suffix
        for (int i=n-2; i >= 0; i--) {
            // suffixes: 1 2 4 6
            // for 4 (i = 2 = n -2)
            // suffixes[2]= nums[i+1] * suffixes[i+1] = nums[3] * suffixes[3]
            // suffixes[2] = 6 * 1 = 6
            suffixes[i] = nums[i+1] * suffixes[i+1];
        }

        // find the product 
        for (int i=0; i < n; i++) {
            result[i] = prefixes[i] * suffixes[i];
        }
        return result;
    }
};
