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
    TreeNode* searchBST(TreeNode* root, int val) {
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* node;
        while (!st.empty()){
            node = st.top();
            st.pop();
            if (val < node->val){
                if (node->left){
                    st.push(node->left);
                } else {
                    return nullptr;
                }
            } else if (val > node->val){
                if (node->right){
                    st.push(node->right);
                } else {
                    return nullptr;
                }
            } else {
                break;
            }
        }
        return node;
    }
};