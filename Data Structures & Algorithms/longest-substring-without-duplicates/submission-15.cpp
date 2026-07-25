class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     /* 
    zxyzxyz
    l
      r
    max_length = 0
    length = 1
    while (r < s.size())
    if (l == r) then r++, length = 1
    if (s[l] != s[r]) then r++, length++;
    if (s[l] == s[r]) then l = r
    max_length = max(length, max_lngth)

    return max_length
     */   
    
    if (s.empty()) {
        return 0;
    }

    unordered_set<char> seen;
    int maxLength = 0;
    int l = 0;
    int r = 0;

    while (r < s.size()) {
        if (!seen.count(s[r])) {
            seen.insert(s[r]);
            maxLength = max(r-l + 1, maxLength);
            r++; 
        } else if (seen.count(s[r])) {
            seen.erase(s[l]);
            l++;
        }
        cout << "left: " << s[l] << "\n";
        cout << "right: " << s[r] << "\n";
        cout << "max: " << maxLength << "\n";
     }

    return maxLength;
    }
};
