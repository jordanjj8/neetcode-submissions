class Solution {
public:
    bool isAnagram(string s, string t) {
        // use a hashmap
        // and compare the maps between the two
        // time: o(n) one pass over s & t
        // space: o(n) for n as number of unique characters
        // if we have a fixed alphabe, then we can use a fixed array of size 26
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for (char c: s) {
            sMap[c]++;
        }
        for (char c: t) {
            tMap[c]++;
        }

        return tMap == sMap;
    }
};
