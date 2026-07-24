class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 1. sort intervals by the first index
        // lexicographical sort, so if the first index is the same,
        // it will compare the second
        sort(intervals.begin(), intervals.end());

        // 2. initialize a results vector
        // a. add the first interval
        vector<vector<int>> results = {intervals[0]};

        // 3. iterate through intervals 
        for (auto& next: intervals) {
            // [1,4] [3,8]
            vector<int>& cur = results.back();
            if (cur[1] >= next[0]) {
                cur[1] = max(cur[1], next[1]);
            } else {
            // [1,2] [3,4]
                results.push_back(next);
            }
        }
        // iterator - next interval
        // compare cur.second to next.first
        // if cur.second >= next.first
        //  cur = results[i]
        // results[i] = {cur.first, max(next.second, cur.second)}
        // else 
        //  results.push_back(next)
        // 4, after iterating, we return results
        return results;

    }
};


/*
[3,6] [1,3] [2,5] [7,8]

output: [1,6] [7,8]

1. sort the first pair
o( n log n) fastest sorting 
pair
[1,3] [2,5] [3,6] [7,8]
2. iterate through each pair
check if pair.second is in the interval of the next one
if yes: we can combine
result: [pair.first, pair+1.second]
if no: iterate to the next pair

*/
