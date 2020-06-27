class Solution {
public:
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& cur, vector<vector<TreeNode*>>& res) {
        if (!root) return; 
        if (res.size() == 2) return;
        
        cur.push_back(root);
        if (root == q || root == p) {
            res.push_back(cur);
        } 
        dfs(root->left, p, q, cur, res);
        dfs(root->right, p, q, cur, res);
        cur.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q) return p;
        vector<vector<TreeNode*>> res;
        vector<TreeNode*> v;
        dfs(root, p, q, v, res);
        TreeNode* ans = nullptr;
        if (res.size() != 2) return ans;
        for (int i = 0; i< res[0].size() && i < res[1].size(); i++) {
            if (res[0][i] == res[1][i]) ans = res[0][i];
            else break;
        }
        return ans;
    }
};
