class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     /* 
    zxyzxyz
    l
      r
    seen <- empty set of characters
    max_length <- 0
    l <- 0, r <- 0
    while r < s.size():
        if s[r] not in seen:
            add s[r] to seen
            max_length <- max(max_length, r - l + 1)
            r <- r + 1
        else:
            remove s[l] from seen
            l <- l + 1
    return max_length

    O(n) time, where n is the size of string
    space O(m) time, where m is the number of uniquue characters 
     */   
    if (s.empty()) {
        return 0;
    }

    // characters in the current window
    unordered_set<char> seen;
    int maxLength = 0; // best window size seen
    int l = 0;
    int r = 0;

    while (r < s.size()) {
        if (!seen.count(s[r])) {
            // expand! 
            seen.insert(s[r]);
            // window spans l to r, inclusive
            maxLength = max(r-l + 1, maxLength);
            r++; 
        } else {
            // shrink from the left until the duplicate at s[r] leaves the window
            seen.erase(s[l]);
            l++;
        }
        // cout << "left: " << s[l] << "\n";
        // cout << "right: " << s[r] << "\n";
        // cout << "max: " << maxLength << "\n";
     }

    return maxLength;
    }
};
