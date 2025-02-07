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
    vector<int> dfs(TreeNode* root1){
        stack<TreeNode*> st;
        vector<int> leaf;
        st.push(root1);
        while (!st.empty()){
            TreeNode* tmp = st.top();
            st.pop();
            if (!tmp->left && !tmp->right){
                leaf.push_back(tmp->val);
            }
            if (tmp->right){
                st.push(tmp->right);
            }
            if (tmp->left){
                st.push(tmp->left);
            }
        }
        return leaf;
    } 
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return dfs(root1) == dfs(root2);
    }
};