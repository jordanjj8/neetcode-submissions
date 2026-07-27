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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        // handle edge case
        if (root == nullptr) {
            return maxDepth;
        }

        // queue will initially hold the node
        queue<TreeNode*> q;
        q.push(root);

        // go through queue until empty
        while (!q.empty()) {
            int queueSize = q.size();
            // process nodes level by level
            for (int i=0; i < queueSize; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            // once level is complete, incement depth
            maxDepth++;
        }

        return maxDepth;
    }
};
