#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    /*
    1. indices hashmap: value to index of all the nums
    2. iterate to populate the indices map
    3. iterate through nums 
    a. calculate different 
    b. if difference is in list and not the same number
    return answer
    */
    unordered_map<int, int> indices;
    
    // 2 populate indices
    for (int i= 0; i < nums.size(); i++) {
        indices[nums[i]] = i;
    }
    // 3. find the partner
    for (int i=0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (indices.count(diff) && indices[diff] != i) {
            // note i is always the smaller index since it walks i from 0
            return {i, indices[diff]}; 
        }
    }

    }

};
