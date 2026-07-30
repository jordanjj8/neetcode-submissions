class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        //create a vector of size nums.size()
        // each index will represent the total count 
        // vector of vector
        // so lets say at index 3, there is a {3,4} vector
        // this means integers 3 and 4 show up 3 times in nums
        // iterate through this vector of vectors and return the first k integers 
        if (k == 0) {
            return vector<int>();
        }
        vector<vector<int>>countToNums(nums.size()+1, vector<int>());
        // map to populate the countToNums
        unordered_map<int,int> numToCount;

        // populate the map
        for (int n: nums) {
            numToCount[n]++;
        }

        // use map to populate the countToNums
        for (const auto& [n, count] : numToCount) {
            countToNums[count].push_back(n);
        }

        // find the first k numbers
        int counter = 0;
        for (int i = nums.size(); i >=0; i--) {
            if (!countToNums[i].empty()) {
                // look through all the nums in list
                for (int j=0; j < countToNums[i].size(); j++) {
                    result.push_back(countToNums[i][j]);
                    counter++;
                    if (counter == k) {
                        return result;
                    }
                }
            }
        }
    }

};
