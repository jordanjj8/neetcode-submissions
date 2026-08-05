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
        // 1. iterate the right pointer with char c through s
        // a. if c is in hash map
        //     then increment l  
        // b. log length and update maxLength
        // b  length = r - l + 1
        // p w w k e w
        //     l
        //     r
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
