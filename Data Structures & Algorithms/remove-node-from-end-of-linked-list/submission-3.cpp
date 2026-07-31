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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // 1 2 3 4 5 6 
       //
       //  n = 5
       // 6-5 = 1 index
       // Given n, remove list length - nth, starting from head
       // first pass to find size of list
       // second pass is to remove the nth node
       int length = 0;
       ListNode* cur = head;
       while (cur != nullptr) {
            length++;
            // advance cur to next node
            cur = cur->next;
       }
       cur = head;
       ListNode* prev = nullptr;
       for (int i =0; i < length-n; i++) {
            // keep a prev up to date
            prev = cur;
            // advance the node to remove
            cur = cur->next;
       }
       if (prev == nullptr) {
            return head->next;
       }
       // remove node
       prev->next = cur->next;

       return head;
    }
};
