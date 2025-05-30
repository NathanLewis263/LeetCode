/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root; // Base case

        TreeNode* left = lowestCommonAncestor(root->left, p, q);   // Search left subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // Search right subtree

        if (left && right) {
            return root;  // If p and q are found in different subtrees, return root
        }
        else if (left){
            return left;
        } else if (right){
            return right;
        } else {
            return nullptr;
        }
    }
};