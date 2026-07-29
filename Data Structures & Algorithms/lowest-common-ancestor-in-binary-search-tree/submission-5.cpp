/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // iterate through binary tree 2 times
        // first pass for p
        // second pass for q
        // along the way, save the ancestor and itself
        // iterate through the stack to find the lowest common ancestor
        stack<TreeNode*> stackP;
        stack<TreeNode*> stackQ;
        // find p
        TreeNode* cur = root;
        while (cur != nullptr) {
            stackP.push(cur);
            if (cur->val > p->val) {
                // look left
                cur = cur->left;
            } else if (cur->val < p->val) {
                // look right
                cur= cur->right;
            } else {
                break;
            }
        }
        // find q
        TreeNode* curr = root;
        while (curr != nullptr) {
            stackQ.push(curr);
            if (curr->val > q->val) {
                // look left
                curr = curr->left;
            } else if (curr->val < q->val) {
                // look right
                curr= curr->right;
            } else {
                break;
            }
        }

        while (!stackQ.empty() && !stackP.empty()) {
            // pop deeper one first
            while (stackQ.size() > stackP.size()) {
                stackQ.pop();
            } 
            while (stackP.size() > stackQ.size()) {
                stackP.pop();
            } 
            // once they have equal size, then pop at the same time
            // and compare
            // the LCA is the one that is the same
            TreeNode* qLCA = stackQ.top();
            TreeNode* pLCA = stackP.top();
            if (qLCA->val == pLCA->val) {
                return qLCA;
            } else {
                stackQ.pop();
                stackP.pop();
            }
        }
    }
};
