class Solution {
public:
    string minWindow(string s, string t) {
        // notes: all of t needs to be included in s 
        // return the full substring
        /*
        PLAN: use left and right pointer (sliding window with frequency maps)
        initltiaze countT, window frequenct map
        1. populate countT with a frequency map of T
        2. initilaize a have and need variables
        have: uniq chars in window
        need: uniq chars in counT
        3. initiaize resIndex and resLength
        resIndex: for returning the substring
        resLength: used for finding the min window
        4. iterate through s with l and r
        a. r will point to c
        b. update window, and update have if c is in countT
        c. while have and need are met, then log the res and try to min 
            1. update resIndices and reesLength
            2. shirnk from l (& remove from window)
                a. update have if need be
        5. return s[resindices + 1] 
        */
        unordered_map<char,int> countT, window;
        for (char c: t) {
            countT[c]++;
        }
        int have = 0;
        int need = countT.size();
    
        // hold result indicies to build substring
        pair<int, int> resIndices = {-1, -1};
        // used to for finding min lenght
        int resLength = INT_MAX; 
        int l = 0;
        //  iterate through s
        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (window[s[r]] == countT[s[r]]) {
                have++;
            }

            while (have == need) {
                // found a result, log it and try to find the min
                if (r - l + 1 < resLength) {
                    // only update if new result is shorter
                    resIndices = {l, r};
                    resLength = r - l + 1;
                }
                window[s[l]]--;
                if (window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (resIndices.first == -1 || resIndices.second == -1) {
            return "";
        } else {
            return s.substr(resIndices.first, resLength);
        }
    }
};
