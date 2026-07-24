#include<cctype>

class Solution {
public:
    bool isPalindrome(const string& s) {
        // iterate through s and ignore all nonalphanumeric characters
        // use two pointers (left and right pointer)
        // - increment l until s[l] is an alpha
        // - decrement r until s[r] is an alpha
        // - compare s[l] and s[r]
        // if !=, then return false
        // if ==, then increment and decrement l & r
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (r > l && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            // if we have found a match, then we can incement/decrement
            l++;
            r--;
        }
        return true;
    }
};
