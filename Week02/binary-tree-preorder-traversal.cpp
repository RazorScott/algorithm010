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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        unordered_set<TreeNode*> visited;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            if (!t) continue;
            if (visited.count(t) == 0) {
                v.push_back(t->val);
                visited.insert(t);
            }
            s.push(t->right);
            s.push(t->left);
        }
        return v;
    }
};
