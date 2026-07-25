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
    bool hasCycle(ListNode* head) {
        // Solution 1: use a hashset
        // iterate through the linkedlist 
        // insert into the set
        // if val is already in set, then we return true
        // time ( O(n) )
        // space ( O(n))
        // unordered_set<ListNode*> seen;
        // ListNode* cur = head;
        // while (cur != nullptr) {
        //     if (seen.count(cur)) {
        //         return true;
        //     } else {
        //         seen.insert(cur);
        //         cur = cur->next;
        //     }
        // }
        // return false;


        // Solution 2: slow and fast pointer
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

