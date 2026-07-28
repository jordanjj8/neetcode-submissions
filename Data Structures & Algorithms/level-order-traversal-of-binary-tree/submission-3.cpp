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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return {};
        } else if (root->left == nullptr && root->right == nullptr) {
            return {{root->val}};
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // capture current size of queue (all the levels)
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++ ) {
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
