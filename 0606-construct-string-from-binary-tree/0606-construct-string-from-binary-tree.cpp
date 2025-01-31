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
    string tree2str(TreeNode* root) { //Most binary tree problems require recursion
        if (!root){ //if no root -> nullptr
            return "";
        }
        string ans = to_string(root->val);
		if (root->left || root->right) //left side check (nullptr if no child is present)
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { //right side check (nullptr if no child is present)
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
	}
};