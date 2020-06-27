class Solution {
public:
    TreeNode* getRoot(vector<int>& preorder, vector<int>& inorder, int p_i, int p_j, int i_i, int i_j) {
        if (p_i >= p_j || i_i >= i_j) return nullptr;
        TreeNode* root = new TreeNode(preorder[p_i]);
        for (int i = i_i; i < i_j; i++) {
            if (inorder[i] == root->val) {
                int t = i - i_i;
                root->left = getRoot(preorder, inorder, p_i+1, p_i+t+1, i_i, i);
                root->right = getRoot(preorder, inorder, p_i+t+1, p_j, i+1, i_j);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return getRoot(preorder, inorder, 0, n, 0, n);
    }
};
