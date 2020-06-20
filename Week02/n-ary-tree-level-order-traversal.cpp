class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            queue<Node*> tq;
            vector<int> v;
            while (!q.empty()) {
                Node* t = q.front();
                q.pop();
                v.push_back(t->val);
                for (auto n : t->children) {
                    if (n) 
                        tq.push(n);
                }
            }
            q = tq;
            res.push_back(v);
        }
        return res; 
    }
};
