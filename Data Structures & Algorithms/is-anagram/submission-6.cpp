class Solution {
public:
    bool isAnagram(string s, string t) {
        // use a hashmap
        // and compare the maps between the two
        // time: o(n) one pass over s & t
        // space: o(n) for n as number of unique characters
        // if we have a fixed alphabe, then we can use a fixed array of size 26
        vector<int> sCount(26, 0);
        vector<int> tCount(26, 0);

        for (char c: s) {
            sCount[tolower(static_cast<unsigned char>(c)) - 'a']++;
        }
        for (char c: t) {
            tCount[tolower(static_cast<unsigned char>(c)) - 'a']++;
        }

        return tCount == sCount;
    }
};
