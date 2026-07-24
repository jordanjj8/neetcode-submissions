/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // prev will hold the new head
        ListNode *prev = nullptr;

        // cur is the node that we unlink and link
        ListNode *cur = head;

        // iterate through cur
        while (cur != nullptr) {
            // save next before reversing
            ListNode *next = cur->next;
            // now the cur's next is prev 
            cur->next = prev;

            // update prev as the old cur
            prev = cur;

            // iterate to next
            cur = next;

        }
    // head will be nullptr at the end of the while loop
    return prev;
    }
};

/*
       0     1        2      3
1. prev  cur >  next 
    prev < cur
2.      prev <  cur  >  next 
                cur < next 
3.         prev >  cur >  next
                     cur < next
4.                           cur next(null)
stop
*/