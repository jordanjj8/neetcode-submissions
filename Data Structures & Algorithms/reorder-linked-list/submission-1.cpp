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
        while (second != nullptr) {
            // ex: 0 1 2   3 4 5 null   even
            //               n
            //             s
            //           p 
            //             s->p
            //                3
            //             4 
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // merge the two halves one by one
        second = prev;
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

    }
};
