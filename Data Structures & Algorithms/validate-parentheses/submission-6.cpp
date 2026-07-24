#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // plan 
        // initialize stack st
        // 1. iterate through each char c of string
        // a. if c is any of the starting, then push
        //   if c == "(" or "{" or "["
        //   then add to st
        // b. if c is any of the ending, then pop
        //    check if popped is of the same type
        // c. if c is anything else, then return false
        // since its not valid
        // 2. after finishing iterating, return true
        
        vector<int> st;

        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            }  else {
                if (st.empty()) {
                    return false;
                }
                char top = st.back();
                if (c == ')') {
                    if (top != '(') {
                        return false;
                    }
                } else if (c =='}') {
                    if (top != '{') {
                        return false;
                    }
                } else if (c ==']') {
                    if (top != '[') {
                        return false;
                    }
                } else {
                    return false;
                }
                st.pop_back();
            }
        }
    
    if (!st.empty()) {
        return false;
    }
    return true;

    }
};
