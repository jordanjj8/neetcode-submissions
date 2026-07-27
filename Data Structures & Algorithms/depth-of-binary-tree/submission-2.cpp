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

        // queue will hold the node & depth level
        queue<pair<TreeNode*, int>> q;
        q.push({root, ++maxDepth});

        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (cur != nullptr) {
                // update maxdepth
                maxDepth = max(maxDepth, depth);
            }
            if (cur->left != nullptr) {
                q.push({cur->left, depth+1});
            }
            if (cur->right != nullptr) {
                q.push({cur->right, depth+1});
            }
        }

        return maxDepth;
    }
};
