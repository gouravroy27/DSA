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
    int sumRootToLeaf(TreeNode* root, int current_sum = 0) {
        if (!root) return 0;
        
        current_sum = (current_sum << 1) | root->val;
        
        if (!root->left && !root->right) {
            return current_sum;
        }
        
        return sumRootToLeaf(root->left, current_sum) + sumRootToLeaf(root->right, current_sum);
    }
};