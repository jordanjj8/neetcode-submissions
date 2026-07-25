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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /* 1   2    4
          cur1
        1     3     5
        cur2

        result = nullptr
        while cur1 is not null and cur2 is not null
         if cur1->value <= cur2->value 
        
            result->cur1
            cur1 = cur1->next
        else

            result->cur2
            cur2 = cur2->next

        if cur1 is null
        then result->cur2
        if cur2 is null
        then reult->cur1
        */        

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        // dummy node avoids special case for the first real node
        ListNode dummy(0);
        // tail is the end of the merged list we are building
        ListNode* result = &dummy;

        // while both lists still have nodes, pick the smaller one
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) { 
                result->next = cur1; // append smaller one
                cur1 = cur1->next; // advance list 1
            } else {
                result->next = cur2;
                cur2 = cur2->next;
            }
            result = result->next; // move tail to the just addded node
        }


        // when one list is empty, attach the rest of the other list
        if (cur1 == nullptr) {
            result->next = cur2;
        } else {
            result->next = cur1;
        }

    return dummy.next; // skip dummy
    }
};
