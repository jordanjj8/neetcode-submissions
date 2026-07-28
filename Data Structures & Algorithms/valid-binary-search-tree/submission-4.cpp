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
    bool isValidBST(TreeNode* root) {
        // dfs or bfs should work
        // 1. iterate through every node in the tree
        // a. check if cur->value > cur->left->val (if cur->left != nullptr)
        // && if cur->value < cur->right->val (if cur->right != nullptr)
        // if not, return false
        // if okay, then add cur->left to stack
        // do the same add cur->right to stack
        if (root == nullptr) {
            return true;
        }

        stack<tuple<TreeNode*, int, int>> s; 
        // LONG_MIN - > min possible number in min
        s.push(make_tuple(root, INT_MIN, INT_MAX));

        while (!s.empty()) {
            auto [cur, left, right] = s.top();
            s.pop();

            if (!(left < cur->val && right > cur->val)) {
                return false;
            }
            if (cur->left != nullptr) {
                s.push(make_tuple(cur->left, left, cur->val));
            }
            if (cur->right != nullptr) {
                 s.push(make_tuple(cur->right, cur->val, right));
            }
        }
        return true;

    }
};
