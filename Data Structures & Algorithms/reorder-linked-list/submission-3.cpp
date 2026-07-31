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
    void reorderList(ListNode* head) {
        /* formula: 0, n-1, 1, n-2, 2, n-3
        we can see that the reorded list is made up one
        alternating starting node and ending node
        we can create this list by 
        1. finding the middle node using fast and slow pointers
        2. splitting the list into 2 halves, where the second half is reversed. 
        3. Then we can merge the two halves one by one, where we take a node from the first hald and then a node fromt the reversed second half and repeat
        */
        ListNode* slow = head;
        ListNode* fast = head->next; 
        
        // find the middle node (slow will point to it)
        // ex: 0 1 2 3 4 null   odd
        //         s,
        //                f
        // ex: 0 1 2 3 4 5 null   even
        //         s,
        //               f
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list in half, with a pointer pointer at 2nd half 
        // first pointer to the start of first half
        // second pointer to the start of the second half
        ListNode* first = head;
        ListNode* second = slow->next; 
        slow->next = nullptr;
        ListNode* prev = nullptr;

        // reverse the second half
        // At this point:
        //   'first' is the head of the first half (e.g., 1 -> 2 -> 3 -> null)
        //   'second' is the head of the second half (e.g., 4 -> 5 -> null)
        //   'prev' should be nullptr; we are building a new reversed list
        while (second != nullptr) {
            /* 
            1 2 3    4 5 
            prev   second   next    after second->next = prev
            null   4        5       4 -> null
            4      5        null    5 -> 4
            5      null     -       done
            */
            ListNode* next = second->next; // remember the rest of the second half
            second->next = prev;  // flip the link: current node points back
            prev = second; // move the head of the reversed list forward
            second = next; // advance to the next original node
        }

        // 'prev' is now the head of the fully reversed second half (e.g., 5).
        // merge the two halves one by one
        second = prev;
        while (second != nullptr) {
            ListNode* tmp1 = first->next; // save first half's next node
            ListNode* tmp2 = second->next; // save reversed half's next node
            first->next = second; // merge one node from reversed half
            second->next = tmp1; // connect the rest of the first half
            first = tmp1; // advance first half pointer 
            second = tmp2; // advance reversed-half pointer
        }
    }
};
