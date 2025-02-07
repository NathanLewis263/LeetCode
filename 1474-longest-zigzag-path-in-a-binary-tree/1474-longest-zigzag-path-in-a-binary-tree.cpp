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
    int longestZigZag(TreeNode* root) {
    int maxlen = 0;
    stack<tuple<TreeNode*,char,int>> st;
    st.emplace(root,'l',0);
    st.emplace(root,'r',0);
    while (!st.empty()){
        auto [node, letter, len] = st.top();
        st.pop();
        maxlen = max(maxlen,len);
        if (letter == 'l'){
            if (node->left){
                st.emplace(node->left,'l',1);
            }
            if (node->right){
                st.emplace(node->right,'r',len+1);
            }
        }  else {
            if (node->right){
                st.emplace(node->right,'r',1);
            }
            if (node->left){
                st.emplace(node->left,'l',len+1);
            }
        }
    }
    return maxlen;
    }
};