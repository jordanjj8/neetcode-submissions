#include <vector>
#include <unordered_map>
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
        unordered_map<char,char> close_to_open = {
            {')', '('},
            {'}', '{'},
            {']','['}
        };
        vector<char> st;


        for (char c: s) {
            // if c is closed 
            if (close_to_open.count(c)) {
                // need to check if st is not empty
                // and that there is an open in st
                // if true, then pop out of st
                // if not, then return false
                if (!st.empty() && st.back() == close_to_open[c]) {
                    st.pop_back();
                } else {
                    return false;
                }
            } else {
                // if c is not closed
                // check that they are open!
                // then push, if not then return false
                st.push_back(c);
            }
        }
        return st.empty();
    }
};
