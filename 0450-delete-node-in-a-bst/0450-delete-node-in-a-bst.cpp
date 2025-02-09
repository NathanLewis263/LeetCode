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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* node;
        TreeNode* prev = nullptr;
        
        while (!st.empty()){
            node = st.top();
            st.pop();
            if (key < node->val){
                if (node->left){
                    st.push(node->left);
                    prev = node;
                }
            } else if (key > node->val){
                if (node->right){
                    st.push(node->right);
                    prev = node;
                }
            } else {
                if (!node->left && !node->right) {
                    if (!prev) {
                        return nullptr;
                    } if (prev->left == node) {
                        prev->left = nullptr;
                    } else {
                        prev->right = nullptr;
                    }
                    delete node;
                }  else if (!node->left) { // Case 2: Node has one child
                    if (!prev) { 
                        return node->right; // If deleting root node
                    } if (prev->left == node) { prev->left = node->right; }
                    else { 
                        prev->right = node->right; 
                    }
                    delete node;
                } else if (!node->right) {
                    if (!prev) { 
                        return node->left; // If deleting root node
                    } if (prev->left == node) { 
                        prev->left = node->left; 
                    }
                    else { 
                        prev->right = node->left; 
                    }
                    delete node;
                }
                // Case 3: Node has two children
                else {
                    TreeNode* successor = findMin(node->right);
                    node->val = successor->val;
                    node->right = deleteNode(node->right, successor->val);
                }
                return root;
            }
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left) { 
            node = node->left; 
        }
        return node;
    }
};