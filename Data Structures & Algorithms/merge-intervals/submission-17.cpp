class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if interval.size() == 1, then return as is
        // results vector of vector (add first interval)
        // 1. sort intervals so that the first value of each inner vector, starting from left is smallest
        // 2. insert the first interval into result  
        // 3. iterate through intervals starting with index 1 using i
        // a. if latest result[1] >= intervals[i][0]
        //  then update the latest result with the max right number of the two
        // b. else add intervals[i] into results
        // 
        // ex: [1,2][3,5][5,8][9,10]
        //                       i   
        // result [1,2], [3,8] [9, 10]
        // modify whats already in result

        if (intervals.size() <= 1) {
            return intervals;
        }

        // sort!
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // [ 1,3] [3,5]
            //    i-1  
            //         i 
            vector<int>& latest_entry = result.back();
            if (latest_entry[1] >= intervals[i][0]) {
                // combine!
                // just need to update the right number
                // update the right entry with the biggest number
                latest_entry[1] = max(latest_entry[1] , intervals[i][1]);
                
            } else {
                result.push_back(intervals[i]);

            }
        }

        return result;
    }
};
