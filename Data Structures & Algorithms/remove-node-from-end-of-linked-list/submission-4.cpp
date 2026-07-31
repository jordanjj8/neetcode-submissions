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
        // Example: 1 2 3 4 5 6, n = 5 -> remove the 2nd node from the head.
        // Strategy: first count length, then walk (length - n) steps from head.

        int length = 0;
        ListNode* cur = head;
        // first pass to find size of list
        while (cur != nullptr) {
            length++;
            // advance cur to next node
            cur = cur->next;
        }

        ListNode* target = head;
        ListNode* prev = nullptr;

        // second pass is to remove the nth node
        for (int i =0; i < length-n; i++) {
            // keep a prev up to date
            prev = target;
            // advance the node to remove
            target = target->next;
        }

        // if prev is still null, remove the head
        if (prev == nullptr) {
            return head->next;
        }

        // unlink target node by relinking prev to target's next
        prev->next = target->next;

        return head;
        }
};
