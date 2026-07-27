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
#include<queue>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // edge case: handle the case where root is null!
        if (root == nullptr) {
            return nullptr;
        }
        // BFS, where we use a queue
        // first add root into queue.
        // loop through queue.
        // after swapping left and right, add left and right to queue 
        // queue<TreeNode*> q;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            // capture the front node
            TreeNode* cur = s.top();
            s.pop(); // pop from the queue

            // swap!
            swap(cur->left, cur->right);
            // TreeNode* temp = cur->left; 
            // cur->left = cur->right;
            // cur->right = temp;

            // only add left to the queue if left is not null
            if (cur->left != nullptr) {
                s.push(cur->left);
            }
            // only add right to the queue if right is not null
            if (cur->right != nullptr) {
                s.push(cur->right);
            }
        }
        return root;
    }
};
