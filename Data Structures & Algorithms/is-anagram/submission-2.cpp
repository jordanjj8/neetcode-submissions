class Solution {
public:
    bool isAnagram(string s, string t) {
        // use a hashmap
        // and compare the maps between the two?
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
