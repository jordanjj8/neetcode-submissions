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
        // use BST, where at each level you compare the p & q values to root, to find the LCA.
        // IDEA:
        // if both p and q are less than current root, then look left
        // if greater than cur root, then look right
        // if one is less than and one is greater than, then we found the LCA
        queue<TreeNode*> que;

        TreeNode* cur = root;
        while (cur != nullptr) {
            if (p->val > cur->val && q->val > cur->val) {
                // look right
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                //look left
                cur = cur->left;
            } else {
                return cur;
            }
        }
    }
};
