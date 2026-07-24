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
        ListNode *prev = nullptr;
        ListNode *cur = head;

        // iterate through cur
        while (cur != nullptr) {
            ListNode *next = cur->next;
            // now the cur's next is the prev pointer
            cur->next = prev;
            prev = cur;
            cur = next;


        }
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