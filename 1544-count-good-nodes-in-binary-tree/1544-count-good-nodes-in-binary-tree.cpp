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
    int goodNodes(TreeNode* root) {
        int count = 0;
        stack<pair<TreeNode*,int>> st;
        st.emplace(root,root->val);
        while (!st.empty()){
            auto [node, currMax] = st.top();
            //cout << node->val << " " << currMax << endl;
            st.pop();
            if (node->val >= currMax){
                count++;
            }
            if (node->right){
                st.emplace(node->right, max(currMax,node->right->val));
            }
            if (node->left){
                st.emplace(node->left, max(currMax,node->left->val));
            }
        }
        return count;
    }
};