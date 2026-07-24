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

        // loop until pointers meet or cross
        while (l < r) { 
            // advance l as long as l is smaller than r &
            // is not an alphanum
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            // advance r if r remains > l and is not alphanum
            while (r > l && !isalnum(s[r])) {
                r--;
            }
            // return if lowecase versions are !=
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
