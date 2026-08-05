class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // left and right pointer 
        // z x y z x y z
        //         l 
        //               r
        // ex 2: x x x x
        //             l
        //               r  
        // ex 3: 
        // p w w e d 
        // l
        //     r
        
        // 1. iterate through s with r
        // a. WHILE s[r] is in set
        //     then narrow window from left (erase from set & increment left)  
        // b. insert s[r] into set and update maxLength
        // b  maxLength = ma(r - l + 1, maxLength)

        // maxLength = 2
        int l = 0;
        int maxLength = 0;
        unordered_set<char> characters;

        for (int r = 0; r < s.size(); ++r) {
            // check if we've seen this char
            while (characters.count(s[r])) {
                // want to move up the window
                characters.erase(s[l]);
                ++l;
            }
            // if we havent seen the char, then add to set
            characters.insert(s[r]);
            maxLength = max(r - l + 1, maxLength);
        }

        return maxLength;
    }
};
